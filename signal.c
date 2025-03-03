#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void hundler(int sig)
{
	if(sig == SIGINT)
	{
		printf("le programme a ete interpter\n");
	}
}
int main()
{
	signal(SIGINT,hundler);
	while(1)
	{
		printf("the program  %d is running...\n",getpid());
		sleep(1);
		//signal(SIGINT,hundler);
	}
	//signal(SIGINT,hundler);
}

