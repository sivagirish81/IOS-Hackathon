#include"header.h"

void parse_and_print()
{
    FILE *fptr;
    char c[1000];
    char* args[5];
    
    int i = 0;
    fptr=fopen("lsmod_file.txt","r"); //opening lsmod file to detect active device drivers
    
    while(fptr)
    {
        fgets(c,sizeof(c),fptr); //reads file line by line 
        char *tk = strtok(c," "); //splits the line based on "whitespace"

	    while(tk != NULL)
	    {
	    	args[i] = tk;   //arg[0] - driver name   arg[1]-size    arg[2]-used by
	    	args[i][strlen(args[i])] = '\0';
	    	i++;
	    	tk = strtok(NULL," ");
        }
        
        if (args[2]-'0')
        {
            int new_fork = fork(); //New Fork to redirect statistics to a separate file

            if (new_fork == 0) //child process
            {
                int fd2 = open(args[0],O_CREAT | O_RDWR | O_TRUNC);  //creating file,naming driver name as file
                dup2(fd2,1);    //redirecting output to respective file
                char* modinfo_output[3]={"modinfo",args[0],NULL};
                execvp(modinfo_output[0],modinfo_output); //executing command
                close(fd2);
            }
            else
            {
                wait(0); //parent waiting for child to terminate
            }
        }
    }
    fclose(fptr);
}
