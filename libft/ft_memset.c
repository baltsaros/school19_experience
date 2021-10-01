#include <stdio.h>

void	*ft_memset(char *dest, int ch, int size)
{
	while (size > 0 && *dest)
	{
		*dest = ch;
		++dest;
		--size;
	}
	return (dest);
}

int		main(void)
{
	char	dest[] = "hello world";

	ft_memset(dest + 3, '$', 10);
	printf("new dest is %s\n", dest);
	return (0);
}