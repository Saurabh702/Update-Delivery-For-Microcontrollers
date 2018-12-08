#include <getopt.h>
#include <fcntl.h>
#include "custom.h"

int main(int argc,char **argv)
{
    if(argc > 1)
    {
        int option = 0;
        char *serverAddr = "http://192.168.149.1:8081/os_project/";
        char *devDesc = UNO;

        while ((option = getopt(argc,argv,"csu")) != -1)
        {
            switch(option)
            {
            case 'c':
                if(!check_updates(serverAddr,devDesc).stat)
                    printf("\nFailed to check for updates\n");
                break;
            case 's':
                printf("\nChecking if device is connected or not !!\n");
                connection_status(devDesc);
                break;
            case 'u':
                upgrade(serverAddr,devDesc);
                break;
            default:
                printf("\n c-> Check for updates: Connects to server and checks if new version is available \n");
                printf(" s-> Check for device status: Checks whether the device is connected or not \n");
                printf(" u-> Upgrade the device: Checks for updates, checks device status and upgrades the device software \n");
                break;
            }
        }

        if(optind < argc)
        {
            printf("\n Unrecognized format for specifying arguments \n");
            printf("\n Syntax: <Program-Name> -<arg1> <arg2> ... <argn> \n");
        }
    }
    else
    {
        printf("\n No Arguments specified \n");
        printf("\n Syntax: <Program-Name> -<arg1> <arg2> ... <argn> \n");
    }

    return 0;
}
