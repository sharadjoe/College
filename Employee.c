#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
int size,i=0,n=0;
char value[30],buf[30];

printf("Enter the number of employees: \t");
scanf("%d",&size);

// creat file
int fd= open("employee.txt",O_RDWR|O_CREAT,0700);
 if(fd == -1)
   {
     printf("Error existing now\n" );
     exit(1);
   }

 printf("Enter the names of %d employees\n",size );

// Write contents into the file
 while(size>0)
     {
       scanf("%s",value);
       write(fd, value, strlen(value));
       write(fd,"\n",strlen("\n"));
       size--;
     }


// Counting Section
 lseek(fd,0,SEEK_SET);
 while(read(fd,&buf[i],1)==1)
      {

         if(buf[i]=='\n')
           {

               // buf[i]=0;


               if(buf[0]=='s')
                 {
                   n++;
                 }
                i=0;
               continue;
           }
         i++;
      }
 close(fd);
 printf("Sucessfully exicuted\n" );
 printf("%d Employees with starting letter S \n",n);

}
