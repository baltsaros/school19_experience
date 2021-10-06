#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *buffer, int ch, size_t n)
{
	unsigned int	i;
	const char	*str;

	i = 0;
	str = buffer;
	while (i < n)
	{
		if (str[i] == ch)
			return (void *)buffer + i;
		++i;
	}
	return (NULL);
}

int	main(void)
{
	char	buffer[] = "hello world!";
	int		ch;
	char	*ret;

	ch = 'o';
	ret = ft_memchr(buffer, ch, 6);
	if (NULL == ret)
		printf("Ch was not found. Ret is '%s'\n", ret);
	else
		printf("Ch was found. Ret is '%s'\n", ret);
	return (0);
}
