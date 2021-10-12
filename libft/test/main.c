#include <stdio.h>

ft_atoi(const char *str);

int	main(void)
{
	char	str[] = "  \t--+-+0234ab567";
	char	str2[] = "  --+-+\v0234ab567";
	char	str3[] = "  ---+-+50234ab567";
	char	str4[] = "1234ab567";
	int		ret;

	ret = ft_atoi("  \t--+-+0234ab567");
	printf("%s\n%d\n", str, ret);
	ret = ft_atoi("  --+-+\v0234ab567");
	printf("%s\n%d\n", str2, ret);
	ret = ft_atoi("  ---+-+50234ab567");
	printf("%s\n%d\n", str3, ret);
	ret = ft_atoi("1234ab567");
	printf("%s\n%d\n", str4, ret);
	return (0);
}
