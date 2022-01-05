#include <stdio.h>
#include <stdlib.h>

static int	check_str(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	if (!(s[i]))
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			++n;
		++i;
	}
	return (n);
}

static char	*ft_strndup(char const *str, size_t size)
{
	char			*dest;
	unsigned int	i;

	if (!(dest = (char *)malloc(sizeof(*dest) * (size + 1))))
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	if (!(spl = (char **)malloc(sizeof(spl) * (check_str(s, c) + 1))))
		return (NULL);
	while (s[start])
	{
		end = 0;
		while (s[start + end] && s[start + end] != c)
			++end;
		if (end > 0)
		{
			spl[i] = ft_strndup(s + start, end);
			++i;
			start = start + end;
		}
		if (s[start])
			++start;
	}
	spl[i] = NULL;
	return (spl);
}

int		main(void)
{
	// char	s[] = "b";
	char	s[] = "aaabcaAaAaefaa a";
	// char	s[] = "bac";
	char	c;
	char	**ret;
	int		j;

	c = 'a';
	ret = ft_split(s, c);
	j = 0;
	while (ret[j])
	{
		printf("str[%d] is '%s'\n", j, ret[j]);
		++j;
	}
	printf("Final amount of strings is %d\n", j);
	free(ret);
	return (0);
}
