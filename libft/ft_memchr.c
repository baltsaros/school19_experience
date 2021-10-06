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
	const char buffer[] = "h\0ello world!";
	int		ch;
	char	*ret;

	ch = 'o';
	ret = ft_memchr(buffer, ch, 6);
	if (NULL == ret)
		printf("Ch was not found. Ret(ft) is '%s'\n", ret);
	else
		printf("Ch was found. Ret(ft) is '%s'\n", ret);
	ret = memchr(buffer, ch, 6);
	if (NULL == ret)
		printf("Ch was not found. Ret(mem) is '%s'\n", ret);
	else
		printf("Ch was found. Ret(mem) is '%s'\n", ret);
	return (0);
}
