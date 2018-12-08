#include <curl/curl.h>
#include "custom.h"

size_t writefunc(void *ptr, size_t size, size_t nmemb, string *s)
{
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);

    if (s->ptr == NULL)
    {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }

    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = EOS;
    s->len = new_len;

    return size*nmemb;
}

string get_version(char *addr)
{
    string response;
    init_string(&response,0);

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, addr);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
        {
            fprintf(stderr, "\ncurl_easy_perform() failed: %s\n",curl_easy_strerror(res));
            response.ptr = NULL;
            response.len = 0;
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return response;
}

status check_updates(char *addr,char *desc)
{
    printf("\nChecking for updates !!\n");

    string res = get_version(addr);
    status s = {NULL,0};
    if(res.ptr != NULL)
    {
        printf("\nHosted Version: %s",res.ptr);
        double server_ver = atof(res.ptr);

        printf("\nObtaining Current Version from Device (make sure the device is connected) !!!\n");
        res = connection_status(desc);

        if(res.ptr == NULL)
            return s;

        string ch = readSerial(res.ptr);

        if(ch.ptr != NULL)
        {
            printf("\nCurrent Version: %s\n",ch.ptr);
            double client_ver = atof(ch.ptr);

            if (server_ver == client_ver)
            {
                printf("\n[*]Current Version is up to date\n");
                return (status)
                {
                    res.ptr,-1
                };
            }
            else if (server_ver > client_ver)
            {
                printf("\n[-]Current Version obsolete. New Version Available\n");
                return (status)
                {
                    res.ptr,1
                };
            }
            else
            {
                printf("\n[+]Hosted Version is lower than current version\n");
                return (status)
                {
                    res.ptr,-1
                };
            }
        }
        else
        {
            printf("\nFailed to read the current version from the device\n");
            return s;
        }
    }
    else
    {
        printf("\nFailed to get the hosted version from the server\n");
        return s;
    }
}
