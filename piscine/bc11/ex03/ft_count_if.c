#include <stdio.h>

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (length > i)
	{
		if ((*f)(tab[i]) > 0)
			++ret;
		++i;
	}
	return (ret);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] < 65 || str[i] > 90)
			return (0);
		++i;
	}
	return (1);
}

int	main(int argc, char **argv)
{

	if (argc > 1)
		printf("n is %d\n", ft_count_if(argv, argc, &ft_str_is_uppercase));
	return (0);
}
