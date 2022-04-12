#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
//#include <sys/wait.h>
//#include <sys/types.h>
int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++; // read mails et increment et write mails
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(int ac, char **av)
{
	pthread_t	th[4];

	int i;
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 4; i++)
	{
		int*	a = malloc(sizeof(int));

		*a = i;
		if (pthread_create(th + i, NULL, &routine, NULL))
		{
			perror("Failed to create thread");
			return (1);
		}
		printf("Thread %d has started\n",i);	
		if (pthread_join(th[i], NULL))
		{
			return (2);
		}
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}
