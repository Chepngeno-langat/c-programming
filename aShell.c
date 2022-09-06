#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
  char cmd[100], argVec[100];
  //environment variable
  char *envVec[] = {(char *) "PATH=/bin", 0};

  size_t n = 100;
  char *parameters = malloc(sizeof(char) * n);

  printf("$ ");
  getline(&parameters, &n, stdin);
  printf("%s", parameters);

  free(parameters);

  while (1)
    {
      if (fork() == -1)
	{
	  perror("Failed!\n");
	  return 1;
	}
      //child process
      if (fork() == 0)
	{
	  execve(cmd, &parameters, envVec);
	}
      //parent process
      else
	{
	  wait(NULL);
	  printf("Success!\n");
	}
    }
}
