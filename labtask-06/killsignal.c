#include <signal.h>
#include <stdio.h>
#include <unistd.h>



int main()
{
	while(1)
	{
		kill(PID,SIGINT);
		printf("Hello Dears %d\n",getpid());
		sleep(1);
	}
	return 0;
}