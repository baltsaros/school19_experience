#include <stdio.h>
#include <string.h>

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

	j = 0;
	size_d = ft_strlen(dest);
	while (src[j])
	{
		dest[size_d] = src[j];
		++j;
		++size_d;
	}
	dest[size_d] = '\0';
	return (dest);
}

int	main()
{
	char	dest[] = "hello";
	char	dest2[] = "hello";
	char	src[] = " world1";
	char	src2[] = " world1";

	printf("initial dest is %s\n", dest);
	printf("dest(ft) is %s\n", ft_strcat(dest, src));
	printf("dest(cat) is %s\n", strcat(dest2, src2));
}
