int        ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 48) || (*str > 57))
		{
			return(0);
		}
		*str++;
	}
	return(1);
}

int        main()
{
    char    *str;

    str = "test";
    ft_str_is_numeric(str);
}
