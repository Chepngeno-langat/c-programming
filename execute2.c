#include <stdio.h>
#include <unistd.h>

int main(void)
{
  char cmd[] = "./userscript.sh";
  char * argVec[] = {"userscript", "arg1", "arg2", "3", NULL};
  char * envVec[] = {NULL};

  printf("Start of execve call %s:\n", cmd);
  printf("=================================================================\n");

  if (execve(cmd, argVec, envVec) == -1)
    {
      perror("Could not execute execve");
    }
  printf("Oops, something went wrong!");
}
