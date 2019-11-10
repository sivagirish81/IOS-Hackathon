//Display the device driver / module statistics currently active in the Operating system. 
//Hint: lsmod, modinfo

//Modules Required
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h>



//First redirect the lsmod info to a file
//Take the contents of the file and pass it aas input to the program.
//Based on whether the driver is used or not display the driver statistics.
int main()
{
    int fd = open("lsmod_file.txt","O_RDWR");

    int id = fork();

    if(id == 0){

    char* lsmod_output[2]={"lsmod",NULL};
    execvp(lsmod_output[0],lsmod_output);

    }
    char* lsmod_output[2]={"lsmod",NULL};
    execvp(lsmod_output[0],lsmod_output);

    //Fd for std output 1




}