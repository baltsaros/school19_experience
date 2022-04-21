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

void	*tt_print(void *args)
{
	int	i;

	i = *(int*)args;
	printf("thread num is %d\n", i);
	usleep(20000);
}

int	main(void)
{
	int	i;
	int	j;
	int	n;
	int	c_usec;
	int	m_usec;
	long	c_sec;
	long	m_sec;
	long	time;
	long	a;
	int		b;

	i = 0;
	n = 2;
	c_sec = 1650551048000;
	m_sec = 1650551048000;
	a = (c_sec - m_sec) * 1000;
	printf("(%ld - %ld) * 1000 = %ld\n", c_sec, m_sec, a);
	c_usec = 73;
	m_usec = 73;
	b = (c_usec - m_usec) / 1000;
	printf ("(%d - %d) / 1000 = %d\n", c_usec, m_usec, b);
	time = a + b;
	printf("%ld + %d = %ld\n", a, b, time);
	// test_time(n);
	// while (i < n)
	// {
	// 	// printf("[%d]: %d\n", i, i + 5 * (i == 0));
	// 	i = (n + i) % n;
	// 	// pthread_create(&p[i], NULL, tt_print, (void *)&i);
	// 	printf("[%d]: %d\n", i, (n + i) % n);
	// 	++i;
	// }
	return (0);
}