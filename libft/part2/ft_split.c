#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	check_str(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
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

char	*ft_split(char const *s, char c)
{
	char	**spl;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(spl = (char **)malloc(sizeof(*spl) * (check_str(s, c) + 1))));
		return (NULL);


}

int		main(void)
{
	char	*s;
	char	c;
	char	**ret;
	int		i;
	int		j;

	s = "bcaef";
	c = 'a';
	ret = ft_split(s, c);
	j = 0;
	while (j < 2)
	{
		i = 0;
		while (ret[i][j])
		{
			write(1, &ret[i][j], 1);
			++i;
		}
		write(1, '\n', 1);
		++j;
	}
	return (0);
}
