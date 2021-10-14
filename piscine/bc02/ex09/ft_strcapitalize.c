#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 65) && (str[i] <= 90))
			str[i] = str[i] + 32;
		++i;
	}
	if ((97 <= str[0]) && (str[0] <= 122))
		str[0] = str[0] - 32;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	ft_strlowcase(str);
	i = 0;
	while (str[i])
	{
		if (!((97 <= str[i] && str[i] <= 122)
				|| (48 <= str[i] && str[i] <= 57)
				|| (65 <= str[i] && str[i] <= 90)))
		{
			++i;
			if ((97 <= str[i]) && (str[i] <= 122))
			{
				str[i] = str[i] - 32;
				++i;
			}
		}
		else
			++i;
	}
	return (str);
}

int	main()
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("first %s\n", str);
	ft_strcapitalize(str);
	printf("second %s\n", str);
	return (0);
}
