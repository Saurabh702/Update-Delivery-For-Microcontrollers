#include "custom.h"

string process(char *command,char *mode,int output)
{
    string psBuffer;
    init_string(&psBuffer,BUFFER_SIZE);

    FILE *pPipe;
    pPipe = _popen(command,mode);

    if( pPipe == NULL)
    {
        printf("\nError in command execution !!\n");
        exit(1);
    }

    if(output)
    {
        while(fgets(psBuffer.ptr,psBuffer.len,pPipe) != NULL)
            printf("%s",psBuffer.ptr);

        if(feof(pPipe))
            printf("\nProcess returned %d\n", _pclose(pPipe));
        else
            printf("\nError: Failed to read the pipe to the end.\n");
    }
    else
        while(fgets(psBuffer.ptr,psBuffer.len,pPipe) != NULL);

    fclose(pPipe);

    return psBuffer;
}
