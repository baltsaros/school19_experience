#include <stdio.h>
#include "ft.h"

// int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	s1[] = "aa";
	char	s2[] = "aaB";

	unsigned int	n;
	int				ret;

	n = 3;
	ret = ft_strcmp(s1, s2);
	printf("return(ft) is %d\n", ret);

}
