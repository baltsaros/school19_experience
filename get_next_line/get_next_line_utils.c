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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	remain;

	remain = size;
	while (*dst && remain > 0)
	{
		++dst;
		--remain;
	}
	len_d = size - remain;
	len_s = 0;
	while (src[len_s])
		++len_s;
	if (remain == 0)
		return (len_d + len_s);
	while (*src && remain > 1)
	{
		*dst = *src;
		++dst;
		++src;
		--remain;
	}
	*dst = '\0';
	return (len_d + len_s);
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