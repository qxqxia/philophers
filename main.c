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
	t_philo	philo;

	if (ac < 5 || ac > 6)
		return (error_exit("Error: incorrect arguments\n"));
	if (start_threads(&philo))
		return 
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock();
	return (0);

