#include <stdio.h>

int		ft_strlen(char *str)
{
	str = "hellothere";
	printf("size of str is %lu\n", sizeof(str));
	return (sizeof(str));
}

int		main()
{
	ft_strlen("test");
	return (0);
