int	ft_check_operator(char *o)
{
	if (o[0] == '\0' || o[1] != '\0')
		return (0);
	if (o[0] == '-' || o[0] == '+' || o[0] == '/'
		|| o[0] == '*' || o[0] == '%')
		return (1);
	return (0);
}
