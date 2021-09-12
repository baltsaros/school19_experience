char  *ft_strlowcase(char *str)
{
	while (*str != '\0')
	{
		if (90 >= *str >= 62)
		{
			*str = *str + 32;
		}
		*str++;
	}
    return (*str);
}

int        main()
{
    char    str[] = "1AESZ";

    printf("first %s\n", str);
    *ft_strlowcase(str);
    printf("third %s\n", str);
    return (0);
}
