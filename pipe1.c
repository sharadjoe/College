#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(void)
{
 int p[2],q[2],pid,i,len;
pipe(p);
pipe(q);
char s1[10],s2[10],buff[10],c;
pid=fork();
if(pid==0)
{
close(p[0]);
close(q[1]);
 printf("\n enter message from child to parent:");
 scanf("%s",s1);
write(p[1],s1,sizeof(s1));
read(q[0],buff,sizeof(buff));
printf("\nparent said:%s\n",buff);
}
if(pid>0)
{
close(p[1]);
close(q[0]);
len=read(p[0],buff,sizeof(buff));
printf("\n child said: %s\n",buff);
printf("\nenter message from parent to child:");
scanf("%s",s2);
write(q[1],s2,sizeof(s2));

}
return 0;
}











