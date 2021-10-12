#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *buffer1, const void *buffer2, size_t n)
{
	unsigned int	i;
	const char		*s1;
	const char		*s2;

	i = 0;
	s1 = buffer1;
	s2 = buffer2;
	while (i < (n - 1) && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}
