//Display the device driver / module statistics currently active in the Operating system. 
#include"header.h"

//First redirect the lsmod info to a file
//Take the contents of the file and pass it as input to the program.
//Based on whether the driver is used or not display the driver statistics.
int main()
{
    

    int id = fork(); //creates child process to execute "lsmod" command

    if(id == 0) //child process
    {
        int fd = open("lsmod_file.txt",O_CREAT | O_RDWR);
        dup2(fd,1);    //redirects lsmod command output to file "lsmod_file/txt" and Fd for std output 1
        char* lsmod_output[2]={"lsmod",NULL};
        execvp(lsmod_output[0],lsmod_output);  //executes "lsmod" command
        close(fd);
    }
    else
    {
        parse_and_print();
        wait(0); //waiting for child to execute
    }
    

    
}
