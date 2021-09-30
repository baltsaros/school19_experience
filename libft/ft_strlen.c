#include <stdio.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		main()
{
	printf("strlen is %d\n", ft_strlen("test"));
	return (0);
}
