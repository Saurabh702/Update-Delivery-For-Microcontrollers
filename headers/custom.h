#ifndef CUSTOM_H_INCLUDED
#define CUSTOM_H_INCLUDED

#include "str.h"

typedef struct status
{
    char *port;
    int stat;
} status;

int download(char *);
string connection_status(char *);
string process(char *,char *,int);
status check_updates(char *,char *);
string readSerial(char *);
void upgrade(char *,char *);

#endif // CUSTOM_H_INCLUDED


