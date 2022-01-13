#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(s2) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		++i;
	}
	s2[i] = '\0';
	return (s2);
}

char	ft_to_uppercase(unsigned int i, char ch)
{
	printf("s[%d] is %c\n", i, ch);
	if (ch >= 97 && ch <= 122)
		ch = ch - 32;
	return (ch);
}

int		main(void)
{
	char	s[] = "Hello world!";
	char	*s_mapped;

	printf("Initial str is '%s'\n", s);
	s_mapped = ft_strmapi(s, &ft_to_uppercase);
	printf("Mapped str is '%s'\n", s_mapped);
	return (0);
}
