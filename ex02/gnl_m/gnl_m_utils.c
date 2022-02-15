#include "gnl_m.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		ft_strchr(char *s, char c)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*us;

	if (!s)
		return (0);
	uc = (unsigned char)c;
	us = (unsigned char *)s;
	i = 0;
	while (us[i])
	{
		if (us[i] == uc)
			return (1);
		++i;
	}
	if (us[i] == uc)
		return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (0);
	i = 0;
	while (i < size * count)
	{
		str[i] = 0;
		++i;
	}
	return (str);
}

char	*ft_strjoin_free(char *rest, char *buf)
{
	size_t	i;
	size_t	j;
	char	*unis;

	if (!rest)
		rest = ft_calloc(1, sizeof(int));
	if (!rest || !buf)
		return (0);
	unis = calloc(ft_strlen(rest) + 1, ft_strlen(buf));
	i = 0;
	while (rest[i])
	{
		unis[i] = rest[i];
		++i;
	}
	j = 0;
	while (buf[j])
	{
		unis[i + j] = buf[j];
		++j;
	}
	free(rest);
	return (unis);
}