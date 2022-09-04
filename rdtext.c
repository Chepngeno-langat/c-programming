#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char text[100];
  printf("Type a line of text here: \n");

  /*scanf("%[^\n]s\n", text);*/

  /*using fgets*/
  fgets(text, 100, stdin);
  text[strlen(text) - 1] = '\0';

  int i;
  for (i = 0; i <= strlen(text); i++)
    {
      printf("%d ", text[i]);
    }
    printf("\n");
  printf("You typed the line: %s\n", text);
  return 0;
}
