#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n - 1) && s1[i] && s2[i] && (s1[i] == s2[i]))
		++i;
	return (s1[i] - s2[i]);
}

int	main()
{
	char	s1[] = "aa";
	char	s2[] = "aaB";
	char	s3[] = "aa";
	char	s4[] = "aaB";
	unsigned int	n;
	int				ret;

	n = 3;
	ret = ft_strncmp(s1, s2, n);
	printf("return(ft) is %d\n", ret);
	ret = strncmp(s3, s4, n);
	printf("return(strncmp) is %d\n", ret);
}
