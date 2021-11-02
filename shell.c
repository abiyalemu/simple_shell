#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - simple shell that can run commands with their
 */
int main(void)
{
  char *string, *token, *delim;
  size_t size = 20;
  pid_t child_pid;
  int status;
  char *av[5];
  char **string_pointer = &string;
  delim = "\n";

  av[1] = NULL;
  string = (char*) malloc(sizeof(char)*size);
  

 
  while(getline(string_pointer, &size, stdin) != -1)
    {
      token = strtok(string, delim);
      av[0] = token;
      
      child_pid = fork();
      if(child_pid == -1)

	  return (1);

      if(child_pid == 0)
	{
	  if(execve(av[0],av, NULL) == -1)
            {
              return (2);
            }
	}
      else
	{
	  wait(&status);
	  
	}
    }
  return 0;
}
