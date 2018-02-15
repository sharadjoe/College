#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

int main()
{
  int fd;
  char buf[50];

  // write

  fd=open("file.txt", O_RDWR);

  if(fd == -1)
  {
      printf("Failed to create and open the file.\n");
      exit(1);
  }

/*  write(fd, "Hello World!\n",13);

  close(fd);*/

  // read

  fd = open("file.txt", O_RDONLY);

  if (fd==-1)
  {
      printf("Failed to open and read the file. \n");
      exit(1);
  }

  read(fd,buf, 50);
  // buf[50]='\0';

  close(fd);

  printf("Read Operation Sucess: \n%s",buf );


  return 0;
}
