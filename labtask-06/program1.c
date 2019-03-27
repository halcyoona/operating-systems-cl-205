#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void main(int argc,char *argv[])
{
	printf("%d",argc);
	argv="/bin/ls";
	int pid;
	pid=fork();
	if(pid<0)
	{
		printf("fork failed");
		exit(1);
	}
	else if(pid==0)
	{
		execve(argv, argc, NULL);
	}
	else
	{
		printf("\n Process id is -%d\n",getpid());
		wait(NULL);
		exit(0);
	} 
}