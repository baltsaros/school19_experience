#include <stdio.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	printf("counter %d\n", i);
	printf("sizeof %lu\n", sizeof(i));
	return (i);
}

int		main()
{
	ft_strlen("test");
	return 0;
}
