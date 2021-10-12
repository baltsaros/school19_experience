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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	r;
	unsigned int	s_len;
	unsigned int	set_len;

	s_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	i = 0;
	r = 0;
	k = 0;
	if (!(s1[i]))
		return (NULL);
	while (s1[i] && i < set_len)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				++r;
			++j;
		}
		++i;
	}
	i = s_len;
	while (s1[i] && i > (s_len - set_len))
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				++r;
			++j;
		}
		--i;
	}
	tr = (char *)malloc(sizeof(*s1) * (s_len - r + 1));
	if (r == 0)
		return (s1);
	else
	{

	}

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