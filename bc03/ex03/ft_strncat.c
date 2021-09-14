int	ft_strlen(char *dest)
{
	int		i;

	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	unsigned int	size_d;
	unsigned int	size_s;

	j = 0;
	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	while (src[j] != '\0' && j < nb)
	{
		dest[size_d] = src[j];
		++j;
		++size_d;
	}
	while (j < nb)
	{
		dest[size_d] = '\0';
		++size_d;
		++j;
	}
	if (size_s == (size_d - j) || size_s > (size_d - j))
	{
		src[size_s - 1] = '\0';
	}
	return (dest);
}


#include <stdio.h>
#include <string.h>
int	main()
{
	char	dest[] = "Hello";
	char	src[] = " world";
	unsigned int	nb;

	nb = 5;
	printf("initial dest is %s\n", dest);
	ft_strncat(dest, src, nb);
	printf("concatenated dest is %s\n", dest);
	// strncat(dest, src, nb);
}
