int		ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 20) || (*str > 127))
		{
			return (0);
		}
		*str++;
	}
	return (1);
}

int		main()
{
	char	*str;

	str = "\a{aesz";
	ft_str_is_printable(str);
	return (0);
}
