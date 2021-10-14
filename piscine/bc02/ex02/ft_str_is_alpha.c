int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 65) || (str[i] > 122))
			return 0;
		if ((str[i] <= 90 ) || (str[i] >= 97))
			++i;
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	char	*str;
	int		ret;

	str = "tEst";
	ret = ft_str_is_alpha(str);
	printf("return is %d\n", ret);
	return (0);
}
