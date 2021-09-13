int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
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
int	main()
{
	char	s1[] = "bcc";
	char	s2[] = "Bcc";
	int		d;

	ft_strcmp(s1, s2);
	d = ft_strcmp(s1, s2);
	printf("return is %d\n", d);
	return (0);
}
