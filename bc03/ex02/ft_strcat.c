int	ft_strlen(char *dest)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	j;
	int	size_d;
	int	size_s;

	j = 0;
	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	printf("size of dest is %d\n", size_d);
	while (src[j] != '\0')
	{
		dest[size_d] = src[j];
		++j;
		++size_d;
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
	char	dest[] = "Ur mom is ";
	char	src[] = "pretty swag";

	printf("initial dest is %s\n", dest);
	ft_strcat(dest, src);
	//strcat(dest, src);
	printf("concatenated dest is %s\n", dest);
	printf("src is %s\n", src);
}