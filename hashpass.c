#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "md5.h"

int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");
    
    if(!in)
    {
        printf("Can't open %s for reading.\n", argv[1]);
        exit(1);
    }
    
    FILE *out = fopen(argv[2], "w");
    
    if(!out)
    {
        printf("Can't open %s for writing.\n", argv[2]);
        exit(1);
    }
    
    
    char line[100];
    while(fgets(line, 100, in)!= NULL)
    {
        fprintf(out, "%s\n", md5(line, strlen(line)-1));
    }
}