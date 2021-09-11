int        ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 97) || (*str > 122))
		{
			return(0);
		}
		*str++;
	}
	return (1);
}

int        main()
{
    char    *str;

    str = "aesz";
    ft_str_is_lowercase(str);
}
