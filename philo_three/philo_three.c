#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>


void	dotest(int n, sem_t *sem)
{
	int i;

	i = 0;
	usleep(10000);
	while(1)
	{
		printf("process number : %d\n", n);
		if(n == 3 && i > 100)
			break;
		usleep(10000);
		i++;
	}
}

int main()
{
	int i = 0;
	pid_t pid[5];
	sem_t *sem;

	sem_unlink("/test");
	sem = sem_open("/test", O_CREAT, S_IRWXU, 1);
	while (i < 5)
	{
		pid[i] = fork();
		if(pid[i] == 0)
		{
			dotest(i, sem);
			exit(2);
		}
		i++;
	}
	int status;
	waitpid(-1, &status, 0);
	i = 0;
	while(i < 5)
	{
		kill(pid[i], SIGTERM);
		kill(pid[i], SIGKILL);
		i++;
	}
	printf("status %d\n", status);

}
