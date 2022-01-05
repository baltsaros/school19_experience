#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (char *)str + i;
		++i;
	}
	return (NULL);
}

int	main(void)
{
	char	str[] = "Hello world!";
	char	ch;
	char	*ret;

	ch = 'o';
	ret = ft_strchr(str, ch);
	if (NULL == ret)
		printf("Ch was not found. Ret is '%s'\n", ret);
	else
		printf("Ch was found. Ret is '%s'\n", ret);
	return (0);
}
