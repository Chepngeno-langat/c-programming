#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char** parse(char* input)
//passing input by breaking it down to single words
{
  char* pieces = strtok(input, " ");

  while (pieces != NULL)
    {
      printf("%s\n", pieces);

      pieces = strtok(NULL, " ");
    }
  
  return 0;
  }

char* read_line()
//Takes input from stdin using the getline() function
{
  char* command;
  size_t n = 100;
  size_t line;

  command = (char*)malloc(sizeof(char) * n);

  if (command == NULL)
    {
      printf("Error: Couldn't allocate memory\n");
      exit (1);
    }
  printf("Input: \n");
  line = getline(&command, &n, stdin);

  return command;
}

int main()
{
  //main loop of shell
  printf("Welcome to sh!\n");
  printf("Made by Karen.\n");
  printf("\n");

  char cmd[100], *argVec[100];
  //environment variable
  char *envp[] = {NULL};
  
  char* input = read_line();

  while (1)
    {
      parse(input);

      int id = fork();
      if (id == -1)
	{
	  perror("FAILED!\n");
	}
      if (id == 0)
	{
	  printf("This is the child process\n");
	  printf("%s\n", input);
	  execve(cmd, argVec, envp);
	}
      else
	{
	  wait(NULL);
	  printf("Success!\n");
	}
      break;
    }
  return 0;
}
/*{
  size_t n = 100;
  char *parameters = malloc(sizeof(char) * n);
  char *command = malloc(sizeof(char) * n);
  
  char cmd[] = "/usr/bin/";
  char *argVec[100] = {NULL};
  //environment variable
  char *envVec[] = {NULL}; /*{(char *) "PATH=/bin", 0};


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
      /*free(parameters);
      break;
    }
    }*/
