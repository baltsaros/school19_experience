#include <semaphore.h>
#include "include/philo.h"

void	test_time(int n)
{
	int	i;
	t_timeval st;
	t_timeval end;

	i = 0;
	gettimeofday(&st, NULL);
	while (i < 10)
	{
		printf("[%d] %d\n", i, n + i);
		++i;
	}
	usleep(2000);
	gettimeofday(&end, NULL);
	printf("sta: sec %ld, ms %ld, usec %d\n", st.tv_sec
		, st.tv_sec * 1000 + st.tv_usec / 1000, st.tv_usec);
	printf("end: sec %ld, ms %ld, usec %d\n", end.tv_sec
		, end.tv_sec * 1000 + end.tv_usec / 1000, end.tv_usec);
	printf("dif: %ld\n", (end.tv_sec * 1000 + end.tv_usec / 1000)
		-(st.tv_sec * 1000 + st.tv_usec / 1000));
}
	sem_t	*print;

void	*tt_print(void *args)
{
	int	i;

	i = *(int*)args;
	sem_wait(print);
	printf("thread num is %d\n", i);
	usleep(20000);
	sem_post(print);
}

int	main(void)
{
	int	i;
	int	j;
	int	n;
	pthread_t	p[2];

	i = 0;
	n = 2;
	print = sem_open("print", O_CREAT, 0644, 1);
	// test_time(n);
	while (i < n)
	{
		// printf("[%d]: %d\n", i, i + 5 * (i == 0));
		i = (n + i) % n;
		pthread_create(&p[i], NULL, tt_print, (void *)&i);
		printf("[%d]: %d\n", i, (n + i) % n);
		++i;
	}
	usleep(400000);
	sem_close(print);
	return (0);
}