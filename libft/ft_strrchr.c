#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	while (i > 0)
	{
		if (str[i - 1] == ch)
			return (char *)str + i - 1;
		--i;
	}
	return (NULL);
}

int	main(void)
{
	char	str[] = "Hello world!";
	char	ch;
	char	*ret;

	ch = 'o';
	ret = ft_strrchr(str, ch);
	if (NULL == ret)
		printf("Ch was not found. Ret is '%s'\n", ret);
	else
		printf("Ch was found. Ret is '%s'\n", ret);
	return (0);
}
