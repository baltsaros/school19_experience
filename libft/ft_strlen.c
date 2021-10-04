#include <stdio.h>

size_t	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	printf("strlen is %ld\n", ft_strlen("test"));
	return (0);
}
