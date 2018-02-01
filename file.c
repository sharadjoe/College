#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
/*
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int creat(const char *pathname, mode_t mode);					
int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
*/
void main()
{
int cr,op,s ;
cr = creat("/home/cec/Desktop/program/test.txt",O_RDWR);
if(cr == -1){
printf("File Already Exists Aborting Creation");
}
op = open("/home/cec/Desktop/program/test.txt",O_RDWR);
s=write(op, "hello geeks\n", strlen("hello geeks\n"));
printf("Hello");

close(op);
}
