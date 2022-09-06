#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
  size_t n = 100;
  char *parameters = malloc(sizeof(char) * n);
  char *command = malloc(sizeof(char) * n);
  
  char cmd[] = "/usr/bin/";
  char *argVec[100] = {NULL};
  //environment variable
  char *envVec[] = {NULL}; /*{(char *) "PATH=/bin", 0};*/


  int id;

  while (1)
    {
      printf("command: ");
      getline(&command, &n, stdin);
      printf("%s", command);
      
      printf("parameters: ");
      getline(&parameters, &n, stdin);
      printf("%s", parameters);

      id = fork();

      if (id == -1)
	{
	  perror("Failed!\n");
	  return 1;
	}
      //child process
      if (id == 0)
	{
	  printf("This is the child process\n");
	  execve(cmd, argVec, envVec);
	}
      //parent process
      else
	{
	  wait(NULL);
	  printf("Success!\n");
	}
      /*free(parameters);*/
      break;
    }
}
