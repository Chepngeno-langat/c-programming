#include <stdio.h>
#include <sys/stat.h>

int main()
{
  //pointer to stat struct
  struct stat sfile;

  //stat system call
  stat("stat.c", &sfile);

  //accessing data
  printf("st_mode = %o\n", sfile.st_mode);
  return 0;
}
