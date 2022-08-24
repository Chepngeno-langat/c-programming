#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
  int fd;
  ssize_t rd, wr;
  char *buf;

  fd = open(filename, O_RDONLY);

  if (filename == 0)
    return(0);
  
  if (fd == -1)
    return(0);

  buf = malloc(sizeof(char)*letters +1);
  if (buf == NULL)
    return(0);

  rd = read(fd, buf, letters);
  if (rd == -1)
    return(0);

  wr = write(1, buf, rd);
  if (wr == -1)
    return(0);

  free(buf);
  close(fd);
  return(wr);
}
