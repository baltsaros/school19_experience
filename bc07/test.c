char	ft_concatenation(int size, char *unistr, char **strs, char *sep)
{
	int		i;
	int		j;
	int		s;

	j = 0;
	while (j < size)
	{
		i = 0;
		s = 0;
		while (strs[j][i])
		{
			*unistr = strs[j][i];
			++unistr;
			++i;
		}
		while (sep[s])
		{
			*unistr = sep[s];
			++unistr;
			++s;
		}
		j++;
	}
	unistr[k] = '\0';
	return (unistr);
}
