#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define EOS '\0'
#define FALSE 0
#define TRUE 1
#define BUFFER_SIZE 128
#define UNO "Arduino Uno"

typedef struct string
{
    char *ptr;
    size_t len;
} string;

void init_string(string *,int);
string string_concat(char *[],int);
void display_string(string);

#endif // STR_H_INCLUDED
