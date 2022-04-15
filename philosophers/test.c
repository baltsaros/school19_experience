#include "philo.h"

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

// int	main(void)
// {
// 	int	i;
// 	int	j;
// 	int	n;

// 	i = 0;
// 	n = 9;
// 	// test_time(n);
// 	while (i < n)
// 	{
// 		// printf("[%d]: %d\n", i, i + 5 * (i == 0));
// 		i = (n + i) % n;
// 		printf("[%d]: %d\n", i, (n + i) % n);
// 		++i;
// 	}
// 	return (0);
// }