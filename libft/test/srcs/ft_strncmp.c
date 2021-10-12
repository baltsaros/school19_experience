#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n)
		++i;
	return (str1[i] - str2[i]);
}
