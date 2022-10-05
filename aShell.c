#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int type_prompt(void)
{
	char *prompt = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, prompt, 2);
		if (writecount == -1)
		exit(0);
	}
	return (0);
}


void read_command (char cmd[], char *par[])
{
  char line;
  int count = 0, i = 0, j = 0;
  char *array[100], *pch;

  ssize_t n = 1024;
  char *buf = malloc(sizeof(char) * n);
  /*par = malloc(sizeof(char) * n);*/

  //read line
  line = getline(&buf, &n, stdin);
  printf("%s\n", buf);

  pch = strtok(buf, " ");

  while (pch != NULL)
    {
      array[i++] = strdup(pch);
      printf("%s\n", pch);
      pch = strtok(NULL, " ");
    }
  strcpy(cmd, array[0]);
  printf("cmd is : %s\n", cmd);

  for (j = 0; j < i; j++)
    {
      par[j] = array[j];
    }
  par[i] = NULL;
  for (int x = 0; x < i; x++)
    {
      printf("parameters are: %s\n", par[x]);
    }
  /* printf("%s\n", par[i++]); */

  free(buf);
  
  return;
}


int main()
{
  char cmd[100], command[100], *parameters[20];
  //environment variable
  char *envp[] = {(char *) "PATH=/usr/bin/", 0};
  int id;

  while (1)
    {
      type_prompt();
      read_command (command, parameters);

      id = fork();
      if (id == -1)
	{
	  perror("FAILED!\n");
	}
      else if (id == 0)
	{
	  strcpy(cmd, "/usr/bin/");
	  strcat(cmd, command);
	  execve(cmd, parameters, envp);
	  printf("command is: %s\n", cmd);
	  printf("par: %s\n", parameters[1]);
	  printf("This is the child process\n");
	}
      else
	{
	  wait(NULL);
	  printf("Success!\n");
	}
      break;
    }
}
