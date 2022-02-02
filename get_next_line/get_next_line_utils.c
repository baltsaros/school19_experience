#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	len_s = 0;
	while (src[len_s])
		++len_s;
	if (size == 0)
		return (len_s);
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len_s);
}

int	ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	x;
	size_t			i;

	str = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == x)
			return (1);
		++i;
	}
	if (str[i] == x)
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str_ch;

	str_ch = (char *)s;
	while (n > 0)
	{
		*str_ch = '\0';
		++str_ch;
		--n;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*unis;
	size_t	i;
	size_t	j;
	size_t	l;

	if (!s1 || !s2)
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2);
	unis = (char *)malloc(sizeof(*unis) * (l + 1));
	if (NULL == unis)
		return (0);
	i = 0;
	while (s1[i])
	{
		unis[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		unis[i + j] = s2[j];
		++j;
	}
	unis[j + i] = '\0';
	return (unis);
}
