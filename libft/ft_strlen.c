#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(void)
{
	printf("strlen is %ld\n", ft_strlen("test"));
	return (0);
}
