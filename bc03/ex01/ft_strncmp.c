int		ft_strncmp(char *s1, char *s2, unsigned int n)
{

}

#include <stdio.h>
int	main()
{
	char	s1[] = "abcd";
	char	s2[] = "abbd";
	unsigned int	n;
	unsigned int	d;

	ft_strncmp(s1, s2, 2);
	d = ft_strncmp(s1, s2, 2);
	printf("return is %u\n", d);
}