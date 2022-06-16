#include "minishell.h"

static int	check_charset(char c, char *charset)
{
	unsigned int	i;

	i = 0;
	
	if (!charset)
		return (0);
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!str[i])
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

char	**ft_split_set(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	char			**spl;

	if (!str)
		return (NULL);
	spl = (char **)malloc(sizeof(*spl) * (count_words(str, charset) + 1));
	if (!spl)
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
