#include <stdlib.h>
int		ft_totallen(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		length;

	j = 0;
	length = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			++length;
			++i;
		}
		++j;
	}
	i = 0;
	while (sep[i])
		++i;
	return (length + i * (size - 1));
}

// char	ft_concatenation(int size, char **strs, char *sep)
// {

// }

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	char	*unistr;
	int		i;
	int		j;
	int		k;
	int		s;

	length = ft_totallen(size, strs, sep);
	unistr = (char *)malloc(sizeof(*unistr) * (length + 1));	
	j = 0;
	k = 0;
	while (k < length)
	{
		i = 0;
		s = 0;
		while (strs[j][i] && j < size)
		{
			unistr[k] = strs[j][i];
			++k;
			++i;
		}
		while (sep[s] && j < size - 1)
		{
			unistr[k] = sep[s];
			++k;
			++s;
		}
		j++;
	}
	unistr[k] = '\0';
	return (unistr);
}

#include <stdio.h>
int		main()
{
	char	*strs[5];

	strs[0] = "hello";
	strs[1] = "there";
	strs[2] = "you";
	strs[3] = "look";
	strs[4] = "great";
	printf("%s\n", ft_strjoin(5, strs, "!"));
	return (0);
}