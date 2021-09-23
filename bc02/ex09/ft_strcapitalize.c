
char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
        if ((str[i] >= 65) && (str[i] <= 90))
        {
            str[i] = str[i] + 32;
        }
        ++i;
    }
    return (str);
}


char  *ft_strcapitalize(char *str)
{
    int        i;

    *ft_strlowcase(str);
    i = 1;
    while (str[i] != '\0')
    {
        if ((97 <= str[0]) && (str[0] <= 122))
            {
                str[0] = str[0] - 32;
            }
        if ((32 <= str[i]) && (str[i] <= 46))
        {
            ++i;
            if ((97 <= str[i]) && (str[i] <= 122))
            {
                str[i] = str[i] - 32;
            }
        }
        else
        {
          ++i;
        }
    }
    return (str);
}

/*
#include <stdio.h>
int        main()
{
    char    str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    printf("first %s\n", str);
    *ft_strcapitalize(str);
    printf("third %s\n", str);
    return (0);
}
*/