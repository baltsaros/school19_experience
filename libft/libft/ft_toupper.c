#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

// int	main(void)
// {
// 	int		ch;

// 	ch = 'a';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = 'A';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = '0';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = '/';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = 'z';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = 'Z';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	return (0);
// }