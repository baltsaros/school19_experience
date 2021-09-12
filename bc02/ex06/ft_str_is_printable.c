int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 20) || (str[i] > 127))
		{
			return (0);
		}
		++i;
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
