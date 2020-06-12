#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	dotest(int i)
{
	int n = 0;
	while(1)
	{
		printf("process number : %d, pid  %d\n", i, getpid());
//		if(n == 100)
//			break;
//		n++;
	}
}

int main()
{
	int i = 0;
	pid_t pids[3];

	while(i < 3)
	{
		pids[i] = fork();
		if(pids[i] == 0)
		{
			dotest(i);
			exit(0);
		}
		i++;
	}

}
