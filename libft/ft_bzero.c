#include <stdio.h>

void	ft_bzero(char *str, int n)
{
	while (n > 0 && *str)
	{
		*str = '\0';
		++str;
		--n;
	}
}

int	main(void)
{
	char	str[] = "hello world";

	ft_bzero(str+4, 5);
	printf("new str is %s\n", str);
	return (0);
}
