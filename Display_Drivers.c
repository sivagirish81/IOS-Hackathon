//Display the device driver / module statistics currently active in the Operating system. 
//Hint: lsmod, modinfo

//Modules Required
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>


int Parser();
//First redirect the lsmod info to a file
//Take the contents of the file and pass it aas input to the program.
//Based on whether the driver is used or not display the driver statistics.
int main()
{
    

    int id = fork();

    if(id == 0)
    {
        int fd = open("lsmod_file.txt",O_CREAT | O_RDWR);
        dup2(fd,1);    
        char* lsmod_output[2]={"lsmod",NULL};
        execvp(lsmod_output[0],lsmod_output);
        close(fd);
    }
    else
    {
        Parser();
        wait(0);
    }
    

    //Fd for std output 1
}

int Parser()
{
    //printf("HI");
    FILE *fptr;
    char c[1000];
    char* args[5];
    /*
    if (fptr=fopen("lsmod_file.txt","r"))                                                               ))
    {
        printf("Device driver statistics not available \n");
        exit(0);

    }
    */
   int i = 0;
   int j;
   fptr=fopen("lsmod_file.txt","r");
    while (fptr )
    {
        fgets(c,100,fptr);
        char *tk = strtok(c," ");
        //j=i;
	    while(tk!=NULL)
	    {
            //printf("HI");
	    	args[i] = tk;
	    	args[i][strlen(args[i])] = '\0';
	    	++i;
	    	tk = strtok(NULL," ");
        }
        printf("Data from the file:%s\n", args[0]);
        //i+=1;

    }
    fclose(fptr);

    return 0;

    //while ()
}

