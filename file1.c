#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fd;
  char buf[5];

  fd = open("hedwig.txt", O_WRONLY | O_CREAT,0600);
    if (fd == -1)
      {
       printf("Failed to create and open file.\n");
       exit(1);
      }
  write(fd, "Ha!\n", 4);

  close(fd);

  fd = open("hedwig.txt", O_RDONLY);
  if (fd == -1)
      {
       printf("Failed to create and open file.\n");
       exit(1);
      }
  read(fd, buf, 4);

  close(fd);

  printf("%s\n", buf);
  
}
