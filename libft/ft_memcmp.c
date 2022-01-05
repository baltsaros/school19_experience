#include "libft.h"

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

int	main(void)
{
	const char	buffer1[] = "\0\0\0cd";
	const char	buffer2[] = "\0\0\0ed";
	const char	buffer3[] = "\0\0\0cd";
	const char	buffer4[] = "\0\0\0ed";

	printf("ret(ft) is %d\n", ft_memcmp(buffer1, buffer2, 4));
	printf("ret(mem) is %d\n", memcmp(buffer3, buffer4, 4));
	return (0);
}
