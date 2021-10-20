#include <stdio.h>

void	ft_compare(char *s1, char *s2, int n)
{
	if (s2 > s1 && s2 < s1 + n)
		printf("s2 is bigger than s1\n");
	if (s2 < s1)
		printf("s2 is smaller than s1\n");
	if (s2 == s1)
		printf("s2 is equal to s1\n");
	if (s2 < s1 + n)
		printf("YOBA\n");
}

int		main(void)
{
	char	s1[] = "testhelloworld";
	char	s2[] = "ABCDaa";
	// int		n;

	ft_compare(s1 + 0, s1, 5);
	ft_compare(s1 + 1, s1, 5);
	ft_compare(s1 + 2, s1, 5);
	ft_compare(s1 + 3, s1, 5);
	ft_compare(s1 + 4, s1, 5);
	ft_compare(s1 + 5, s1, 5);
	ft_compare(s1 + 6, s1, 5);
	ft_compare(s1 + 7, s1, 5);
	ft_compare(s1 + 14, s1, 5);
	ft_compare(s2, s1, 5);
	return (0);
}