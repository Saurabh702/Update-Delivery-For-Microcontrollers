#include "custom.h"

string connection_status(char *devDesc)
{
    char *cmd1 = "cmd /Q /C FOR /F \"tokens=* USEBACKQ\" %F IN  \
                  (`powershell \"Get-WMIObject Win32_SerialPort  \
                  | Where-Object {$_.Description -eq '";

    char *cmd2 = "'} | Select-Object -expand DeviceID\"`) DO (echo %F)";

    string command = string_concat((char *[])
    {
        cmd1,devDesc,cmd2
    },3);

    string response = process(command.ptr,"rt",FALSE);
    response.ptr[strlen(response.ptr)-1] = EOS;

    if(strcmp(response.ptr,"") == 0)
    {
        printf("\nDevice is disconnected\n");
        return (string)
        {
            NULL,0
        };
    }
    else
    {
        printf("\nDevice is connected at %s\n",response.ptr);
        return response;
    }
}
