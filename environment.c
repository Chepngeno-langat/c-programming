#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char * envp[])
{
  printf("Accessing environment variables with getenv\n");
  printf(" USER=%s\n", getenv("USER"));
  printf(" HOME=%s\n", getenv("HOME"));
  printf(" UNDEFINED=%s\n", getenv("UNDEFINED"));
  printf(" TERM=%s\n", getenv("TERM"));

  printf("\nContents of envp:\n");
  char ** curr = envp;
  int env_count = 0;
  while (*curr != NULL)
    {
      printf(" %3d: %s\n", env_count, *curr);
      env_count++;
      curr++;
    }
  return 0;
}
