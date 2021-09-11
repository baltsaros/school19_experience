int        ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 65) || (*str > 90))
		{
			return (0);
		}
		*str++;
	}
	return (1);
}

int        main()
{
    char    *str;

    str = "aesz";
    ft_str_is_uppercase(str);
}
