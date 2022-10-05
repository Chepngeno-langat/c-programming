#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

//write prompt
int prompt(void)
{
  char *prompt = "$ ";
  ssize_t writecount = 0;

  if (isatty(STDIN_FILENO) == 1)
    {
      writecount = write(STDOUT_FILENO, prompt, 2);
      if (writecount == -1)
      exit (0);
    }
  return 0;
}


//reads stdin and stores it in a buffer
char *_read(void)
{
  ssize_t readcount = 0;
  size_t n = 0;
  char *buffer = NULL;
  int i = 0;

  readcount = getline(&buffer, &n, stdin);
  if (readcount == -1)
    {
      free(buffer);
      if (isatty(STDIN_FILENO) != 0)
	write(STDOUT_FILENO, "\n", 1);
      exit (0);
    }
  if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
    buffer[readcount - 1] == '\0';
  for (i = 0; buffer[i]; i++)
    {
      if (buffer[i] == '#' && buffer[i - 1] == ' ')
	{
	  buffer[i] = '\0';
	  break;
	}
    }
  return (buffer);
}


//finds string to call execve on
char *_fullpathbuffer(char **av, char *PATH, char *copy)
{
  char *tok, *fullpathbuffer = NULL, *concatstr = NULL;
  static char tmp[256];
  int PATHcount = 0, fullpathflag = 0, z = 0, toklen = 0;

  struct stat h;

  copy NULL;
  copy = _strdup(PATH);
  PATHcount = _splitPATH(copy);
  tok = strtok(copy, ": =");
  while (tok != NULL)
    {
      concatstr = _concat(tmp, av, tok);
      if (stat(concatstr, &h) == 0)
	{
	  fullpathbuffer = concatstr;
	  fullpathflag = 1;
	  break;
	}
      if (z < PATHcount - 2)
	{
	  toklen = _strlen(tok);
	  if (tok[toklen + 1] == ':')
	    {
	      if (stat(av[0], &h) == 0)
		{
		  fullpathbuffer = av[0];
		  fullpathflag = 1;
		  break;
		}
	    }
	}
      z++;
      tok = strtok(NULL, ":");
    }
  if (fullpathflag == 0)
    fullpathbuffer = av[0];
  free(copy);
  return (fullpathbuffer);
}

int main()
{
  char* input;
  input = _read();
  printf("you entered: %s\n", input);
}
