int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] == s2[i])
		{
			++i;
		}
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char	s1[] = "a";
	char	s2[] = "ac";
	unsigned int	n;
	int				ret;

	n = 3;
	ret = ft_strncmp(s1, s2, n);
	printf("return(ft) is %d\n", ret);
	ret = strncmp(s1, s2, n);
	printf("return(strncmp) is %d\n", ret);
}
