#include "custom.h"

void upgrade(char *addr,char *desc)
{
    status s = check_updates(addr,desc);

    if(s.stat == FALSE)
        printf("\nFailed to check for updates\n");
    else if(s.stat == TRUE)
    {
        printf("\nUpdating device !!\n");
        if(download(addr))
        {
            if (strcmp(desc,UNO) == 0)
            {
                process(string_concat((char *[])
                {"cd avrdude && avrdude -v -patmega328p -carduino -P",s.port," -b115200 -D -Uflash:w:package.hex:i"
                },3).ptr,"rt",TRUE);
            }
        }
        else
        {
            printf("\nUpgrade Failed\n");
        }
    }
}
