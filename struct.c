#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct myStructure {
  int myNum;
  char myLetter;
  char myString[30];
};

int main ()
{
  struct myStructure s1; /*= {13, 'B', "some text"};*/
  struct myStructure s2;

  s1.myNum = 13;
  s1.myLetter = 'B';
  strcpy(s1.myString, "Some text");

  s2 = s1;

  printf("My number: %d\n", s2.myNum);
  printf("My letter: %c\n", s2.myLetter);
  printf("My string: %s\n", s2.myString);


  return 0;
}
