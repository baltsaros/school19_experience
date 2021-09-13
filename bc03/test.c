int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int 			k;

	i = 0;
	k = -1;
	while (i < n)
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] < s2[i])
		{
			return (k);
		}
		if (s1[i] == s2[i])
		{
			++i;
		}
	}
	return (0);
}

#include <stdio.h>
int	main()
{
	char	s1[] = "abAd";
	char	s2[] = "abzd";
	unsigned int	n;
	unsigned int	d;

	ft_strncmp(s1, s2, 3);
	d = ft_strncmp(s1, s2, 3);
	printf("return is %u\n", d);
}
