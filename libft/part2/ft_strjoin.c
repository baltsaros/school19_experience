#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*unis;
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;

	l = ft_strlen(s1) + ft_strlen(s2);
	unis = (char *)malloc(sizeof(*unis) * (l + 1));
	if (NULL == unis)
		return (NULL);
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

int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = " world!";
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (NULL == ret)
		printf("Ret is null!\n");
	else
		printf("Ret is '%s'\n", ret);
	free(ret);
	return (0);
}
