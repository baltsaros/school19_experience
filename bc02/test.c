int		ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A') || (str[i] > 'z'))
		{
			return 0;
		}
		if ((str[i] <= 'Z' ) || (str[i] >= 'a'))
		{
			i++;
		}
		else
		{
			return (0);
		}
	}	
	return (1);
}

int		main()
{
	char	*str;

	str = "test";
	ft_str_is_alpha(str);
}
