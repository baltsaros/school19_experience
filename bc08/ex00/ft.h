#ifndef FT_H_
#define FT_H_
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(int *a, int *b)
{
	int		c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_putstr(char *str)
{
	int		i;
	
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		++i;
	}
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		++i;
	}
	return (s1[i] - s2[i]);
}
#endif