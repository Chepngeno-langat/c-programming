#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
  char cmd[100], command[100], *parameters;
  //environment variable
  char * envp[] = {NULL};
  int id;

  while (1)
    {
      type_prompt;
      read_command (command, parameters);

      id = fork();
      if (id == -1)
	{
	  perror("FAILED!\n");
	}
      if (id == 0)
	{
	  execve(cmd, parameters, envp);
	}
      else
	{
	  wait(NULL);
	}
      break;
    }
  
  return 0;
}
  
