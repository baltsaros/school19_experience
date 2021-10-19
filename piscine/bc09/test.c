#include <stdio.h>
#include <stdlib.h>

int		check_charset(char *str, char *cs)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;

	i = 0;
	n = 1;
	if (str[i] == 0 || cs[i] == 0 )
		return (0);
	while (str[i] == cs[i])
	{
		++i;
		if (cs[i] == 0)
			n = 0;
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == cs[j] && str[i + j] && cs[j])
		{
			++j;
			if (cs[j] == 0 && str[i + j] != 0)
				++n;
		}
		++i;
	}
	return (n);
}

char	*ft_strndup(char *str, size_t size)
{

}

char	**ft_split(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	unsigned int	end;
	char			**spl;

	if (str == 0)
		return (NULL);
	if (!(spl = (char **)malloc(sizeof(*spl) * (check_charset(str, charset) + 1))))
		return (NULL);
	i = 0;
	start = 0;
	while (str[start])
	{
		end = 0;
		j = 0;
		while (str[start] == charset[j] && str[start])
		{
			++start;
			++j;
		}
		j = 0;
		while (str[start + end] != charset[j] && str[start + end])
		{
			++end;
		}
		spl[i] = ft_strndup(str + start, end - start);
	}
	
	return (spl);
}

int		main(void)
{
	char	str[] = "HelloTOP world!";
	char	charset[] = "TOP";
	char	**ret;
	int		j;

	ret = ft_split(str, charset);
	j = 0;
	while (ret[j])
	{
		printf("ret[%d] is '%s\n'", j, ret[j]);
		++j;
	}
	return (0);
}
