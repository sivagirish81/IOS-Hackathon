#include "./Driver_Header.h"
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h>
int Parser(int fd)
{
    FILE *fptr;
    char* c[1000];
    char* args[5];
    if ((fptr=fopen(fd,"r")==NULL))
    {
        printf("Device driver statistics not available \n");
        exit(0);
    }
    while (fptr!=NULL)
    {
        fscanf(fptr,"%[^\n]", c);
        tk = strtok(c," ");
	    int i = 0;
	    while(tk!=NULL)
	    {
	    	args[i] = tk;
	    	args[i][strlen(args[i])] = '\0';
	    	++i;
	    	tk = strtok(NULL," ");
	    }
        printf("Data from the file:\n%s", c);
    }
    fclose(fptr);
    //while ()
}

