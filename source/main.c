#include <getopt.h>
#include <fcntl.h>
#include "custom.h"

int main(int argc,char **argv)
{
    if(argc > 1)
    {
        int option = 0;
		opterr = 0; // silence getopt function error handling
        char *serverAddr = "http://127.0.0.1:8081/updates/"; // Server Address 
        char *devDesc = UNO; // Device Type

		while((option = getopt(argc,argv,"+csuh")) != -1)
		{
			if(option == '?')
			{
				printf("\n Unrecognized argument %c \n",optopt);
				printf("\n Try : <Program-Name> -h \n");
				exit(0);
			}
		}
		if(optind < argc)
        {
            printf("\n Unrecognized format for specifying arguments \n");
            printf("\n Syntax: <Program-Name> -<arg1> <arg2> ... <argn> \n");
			exit(0);
        }
		
		optind = 0;
		while ((option = getopt(argc,argv,"csuh")) != -1)
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
            case 'h':
                printf("\n c-> Check for updates: Connects to server and checks if new version is available \n");
                printf(" s-> Check for device status: Checks whether the device is connected or not \n");
                printf(" u-> Upgrade the device: Checks for updates, checks device status and upgrades the device software \n");
				break;
			case '?': continue;
			default:
				printf("\n Unrecognized argument \n");
				printf("\n Try : <Program-Name> -h \n");
				exit(0);
                break;
            }
        }
    }
    else
    {
        printf("\n No Arguments specified \n");
        printf("\n Syntax: <Program-Name> -<arg1> <arg2> ... <argn> \n");
		exit(0);
    }

    return 0;
}
