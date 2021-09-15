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
	char	dest[20] = "hello";
	char	src[] = " worldddddddd";

	printf("initial dest is %s\n", dest);
	ft_strcat(dest, src);
	printf("dest(ft) is %s\n", dest);
	// strcat(dest, src);	
}