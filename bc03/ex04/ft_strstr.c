int	ft_strlen(char *dest)
{
	int		i;

	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size_f;

	size_f = ft_strlen(to_find);
	i = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (j + 1 == size_f)
				return (&str[i + j + 1 - size_f]);
			++j;
		}
		++i;
	}
	return (0);
}


#include <stdio.h>
#include <string.h>
int	main()
{
	char	str[] = "hayNNeedleHay";
	char	to_find[] = "";
	char	*ret;

	ret = ft_strstr(str, to_find);
	printf("return is %s\n", ret);
	ret = strstr(str, to_find);
	printf("return is %s\n", ret);
	return (0);
}
