#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* Created by: Ben Smith
 * Class: CS3060 X01 summer 2021 B1
 * Assignment: Project 2
 */

int main(int argc, char * const argv[])
{
	pid_t pid;
	pid = fork();

	int p_id = getpid();
	int process_id =0;
	int status;

	if (pid < 0)
	{
		perror("Error: Fork function failed\n");
		exit(1);
	}
	else if(pid == 0) //child process
	{
		if(argc == 1)
			printf("CHILD stared. No arguments provided. Terminating child.\n");
		else if(argc > 1)
		{
			if(argc == 2)
				printf("CHILD stared. One argument provided. Calling execlp, never to return.\n");
			else
				printf("CHILD stared. More than one argument provided. Calling execlp, never to return.\n");

			if(execvp(argv[1], argv+1) == -1);
			{	
				perror("execve");
        		exit(1);
        	}
    	}
		exit(0);
	}
	else // parent process
	{
		printf("PARENT started, now waiting for process ID: #%d\n", pid);
		waitpid(pid, &status, 0);

		printf("PARENT resumed. Child exit code of %d. Now terminating parent.\n", status);
               
	}

}