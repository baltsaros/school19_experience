
int		ft_strlen(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		d;
	int		j;

	d = ft_strlen(dest);
	j = 0;
	while (j != d)
	{
		if (j <= n)
		{
			dest[j] = src[j];
			j++;
		}
		else
		{
			dest[j] = '\0';
			j++;
		}
	}
}

/*
#include <stdio.h>
int		main()
{
	char	dest[] = "destination";
	char	src[] = "source";
	int		n;

	n = ft_strlen(src);
	printf("strlen SRC is %d\n", n);
	printf("sizeofsrc is %lu\n", sizeof(src));
	printf("dest is %s\n", dest);
	printf("sizeof DEST is %lu\n", sizeof(dest));
	*ft_strncpy(dest, src, n);
	printf("dest2 is %s\n", dest);
	printf("sizeof2 DEST is %lu\n", sizeof(dest));
}
*/