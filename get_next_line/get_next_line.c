#include "get_next_line.h"

// char	*ft_read(int fd, int i)
// {

// }

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
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
			return ((char *)str + i);
		++i;
	}
	if (str[i] == x)
		return ((char *)str + i);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_ch;
	char	*dest_ch;

	if (dest == src)
		return (dest);
	src_ch = (char *)src;
	dest_ch = (char *)dest;
	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (n > i)
	{
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (dest);
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

char	*get_next_line(int fd)
{
	char			*ret;
	char			*temp;
	static char		buf[BUFFER_SIZE];
	ssize_t			r_bytes;
	ssize_t			i;

	if (fd < 0)
		return (0);
	i = 0;
	r_bytes = read(fd, buf, BUFFER_SIZE);
	if (r_bytes < 0)
		return (0);
	temp = malloc(sizeof *temp * BUFFER_SIZE);
	if (!temp)
		return (0);
	while (buf[i] && buf[i] != '\n')
		++i;
	if (buf[i] == '\n')
	{
		ft_strlcat(temp, buf, BUFFER_SIZE - i);
		ret = malloc(sizeof *ret * (i + 1));
		if (!ret)
			return (0);
		ft_memcpy(ret, buf, i + 1);
		return (ret);
	}
	if (!buf[i])
		return (0);
	temp = buf;
	ret = get_next_line(fd);
	free(temp);
	return (ret);
}


#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*ret;
	int		fd;
	size_t	i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("OPEN ERROR\n");
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		ret = get_next_line(fd);
		printf("str is %s", ret);
		free(ret);
		++i;
	}
	return (0);
}