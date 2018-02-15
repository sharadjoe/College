#include<stdio.h>
#include<sys/types.h>

#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main (void)
{
	int fd,len,times;
	char buf1[30] ;

	fd = open("file.txt", O_RDWR);
        printf("Enter the no of items you want to enter");
scanf("%d",&times);
	while(times > 0){
	times--;
        scanf("%s",buf1);
	write(fd, buf1, strlen(buf1));
	/*printf("\nEntered item \n");*/
	}
	lseek(fd,0,0);
	for (int i=0;i<times;i++)
		 {
		 	/* code */

		 }

close(fd);

	return 0;
}
