#include <stdio.h>

int main()
{
  char input[30];

  fgets(input, 100, stdin);
  printf("user input is: %s\n", input);
}
