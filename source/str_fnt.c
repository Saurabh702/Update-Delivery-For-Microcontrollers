#include "str.h"

void init_string(string *s,int len)
{
    s->len = len;
    s->ptr = malloc(s->len+1);

    if (s->ptr == NULL)
    {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }

    s->ptr[0] = '\0';
}

void display_string(string s)
{
    printf("%s",s.ptr);
}

string string_concat(char *s[],int count)
{
    //works only if count > 2

    string temp;
    int total_len = 0;

    for(int i = 0; i < count; i++)
        total_len += strlen(s[i]);

    init_string(&temp,total_len);
    strcpy(temp.ptr,s[0]);

    for(int i = 1; i < count; i++)
        strcat(temp.ptr,s[i]);

    return temp;
}
