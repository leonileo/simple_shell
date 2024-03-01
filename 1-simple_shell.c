#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


/**
 * main - a simple commandline interpreter
 *
 * Return: Always 0.
 */


int main(void)
{
extern char **environ;
int status;
char *buff = NULL;
size_t buff_size = 0;
char *piece;
char **arr;
pid_t child_pdt;
 
while(1)
{
  write(STDIN_FILENO, "#cisfun$ ", 9);
  if(getline(&buff, &buff_size, stdin) != EOF)
    {
      arr = malloc(32 * sizeof(char *));
      piece = strtok(buff, "\t\n");

      arr[0] = piece;
      piece = strtok(NULL, "\t\n");
      arr[1] = piece;
      child_pdt = fork();

      if(child_pdt == -1)
	{
	  perror("Error");
	  return (1);
	}

      if(child_pdt == 0)
	{
	  if(execve(arr[0], arr, environ) == -1)
	    {
	      perror("./shell");
	    }
	}
      else
	{
	  wait(&status);
	}	
    }
  else
    {
      printf("\n");
      return (1);
    }
  free(arr);
}
return (0);
}
