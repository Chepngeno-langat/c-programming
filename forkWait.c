#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main(void)
{
  char cmd[] = "/usr/bin/ls";

  char * argVec[] = {"ls", "-l", "/tmp", NULL};
  char * envVec[] = {NULL};

  pid_t my_pid;
  pid_t child_pid = 1;

  int i = 1;

  my_pid = getpid();

  while (i <= 5 && (child_pid != 0))
	{
	  child_pid = fork();
	  if (child_pid == -1)
	    {
	      printf("error!\n");
	      return (1);
	    }
	  wait(NULL);
	  i++;
	}
  if (child_pid == 0)
    {
      printf("========================================\n");
      printf("This is the child process with pid: %u\n", getpid());
      printf("========================================\n");
    }
  else
    {
      printf("This is the parent process with pid: %u", my_pid);
    }

  if (execve(cmd, argVec, envVec) == -1)
    {
      perror("Could not execute execve");
    }
  return 0;

  /*printf("Start of execve call %s:\n", cmd);
  printf("====================================================\n");

  if (execve(cmd, argVec, envVec) == -1)
    {
      perror("Could not execute execve");
    }
    printf("Oops, something went wrong!");*/
}
