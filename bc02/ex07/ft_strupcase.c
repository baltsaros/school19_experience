char  *ft_strupcase(char *str)
{
    int		i;

	i = 0;
	while (str[i] != '\0')
    {
        if ((str[i] >= 97) && (str[i] <= 122))
        {
            str[i] = str[i] - 32;
        }
        ++i;
    }
    return (str);
}

#include <stdio.h>
int        main()
{
    char    str[] = "1aesz";

    printf("first %s\n", str);
    *ft_strupcase(str);
    printf("third %s\n", str);
	return (0);
}
