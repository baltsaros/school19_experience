#include <stdio.h>
#include <stdlib.h>

int		check_charset(char c, char *charset)
{
	unsigned int	i;

	i = 0;
	
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		while (str[i] && check_charset(str[i], charset))
			++i;
		if (str[i])
			++n;
		while (str[i] && (!(check_charset(str[i], charset))))
			++i;
	}
	return (n);
}

char	*ft_strndup(char *str, size_t size)
{
	unsigned int	i;
	char			*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * (size + 1))))
		return (NULL);
	i = 0;
	while (size > i && str[i])
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	char			**spl;

	if (str == 0)
		return (NULL);
	if (!(spl = (char **)malloc(sizeof(*spl) * (count_words(str, charset) + 1))))
		return (NULL);
	i = 0;
	start = 0;
	while (str[start])
	{
		end = 0;
		while (str[start] && check_charset(str[start], charset))
			++start;
		while (str[start + end] && (!(check_charset(str[start + end], charset))))
			++end;
		if (end > 0)
		{
			spl[i] = ft_strndup(str + start, end);
			++i;
			start += end;
		}
	}
	spl[i] = '\0';
	return (spl);
}

int		main(void)
{
	char	str[] = "";
	char	charset[] = "1";
	char	**ret;
	int		j;

	ret = ft_split(str, charset);
	j = 0;
	while (ret[j])
	{
		printf("ret[%d] is '%s'\n", j, ret[j]);
		++j;
	}
	return (0);
}
