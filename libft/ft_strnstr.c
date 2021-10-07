#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (little[j] == '\0')
		return (char *)big;
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (j + 1 == n && little[j])
				return (char *)big + i;
			++j;
		}
		++i;
	}
	return (0);
}

int	main(void)
{
	char	big[] = "LittleBig!";
	char	little[] = "Big?";
	char	*ret;

	ret = ft_strnstr(big, little, 4);
	if (ret == NULL)
		printf("Little was not found!\n");
	else
		printf("Little was found! Return is '%s'!\n", ret);
	return (0);
}
