#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char const *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		check_set(int ch, char const *set)
{
	int		i;

	i = 0;
	while(set[i])
	{
		if (ch == set[i])
			return (1);
		++i;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char	*src_ch;
	char	*dest_ch;
	
	src_ch = (char *)src;
	dest_ch = (char *)dest;
	i = 0;
	while (n > i && src_ch[i])
	{
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tr;
	int		i;
	int		start;
	int		end;

	i = 0;
	if (!(s1[i]))
		return (NULL);
	if (!(set[i]))
		return (char *)s1;
	while (check_set(s1[i], set))
		++i;
	start = i;
	i = ft_strlen(s1) - 1;
	while(check_set(s1[i], set))
		--i;
	end = i + 1;
	if (start >= end)
		return (NULL);
	tr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) - end + 2));
	if (NULL == tr)
		return (NULL);
	ft_memcpy(tr, s1 + start, (end - start));
	tr[end - start] = '\0';
	return (tr);
}

int		main(void)
{
	printf("0 : %s", ft_strtrim("str0str", "str"));
	printf("\n");
	printf("01234 : %s", ft_strtrim("01234str", "str"));
	printf("\n");
	printf("01234 : %s", ft_strtrim("str01234", "str"));
	printf("\n");
	printf("012str34 : %s", ft_strtrim("str012str34str", "str"));
	printf("\n");
	printf("01234 : %s", ft_strtrim("01234", "str"));
	printf("\n");
	printf("012345 : %s", ft_strtrim("strstr012345strstr", "str"));
	printf("\n");
	printf("str01234str : %s", ft_strtrim("str01234str", ""));
	printf("\n");
	printf("str01234str : %s", ft_strtrim("str01234str", "k"));
	printf("\n");
	printf("01234ttttt : %s", ft_strtrim("sssss01234tttttr", "rs"));
	printf("\n");
	printf("%s", ft_strtrim("strstr", "str"));
	printf("\n");
	printf("%s", ft_strtrim("", "str"));
	printf("\n");
	printf("%s", ft_strtrim(NULL, "str"));
	printf("\n");
	printf("%s", ft_strtrim("str", NULL));
	printf("\n");
	printf("%s", ft_strtrim(NULL, NULL));
	return (0);
}