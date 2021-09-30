#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		++i;
	return (s1[i] - s2[i]);
}

int	main()
{
	char	s1[] = "abcd";
	char	s2[] = "";
	char	s3[] = "abcd";
	char	s4[] = "";
	int		d;

	ft_strcmp(s1, s2);
	d = ft_strcmp(s1, s2);
	printf("return(ft) is %d\n", d);
	d = strcmp(s3, s4);
	printf("return(strcmp) is %d\n", d);
	return (0);
}
