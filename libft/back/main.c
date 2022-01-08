#include "includes/libft.h"
char	**ft_split(char const *s, char c);

int		main(void)
{
	// char	s[] = "b";
	char	s[] = "aaabcaAaAaefaa a";
	// char	s[] = "bac";
	char	c;
	char	**ret;
	int		j;

	c = 'a';
	ret = ft_split(s, c);
	j = 0;
	while (ret[j])
	{
		printf("str[%d] is '%s'\n", j, ret[j]);
		++j;
	}
	printf("Final amount of strings is %d\n", j);
	free(ret);
	return (0);
}
