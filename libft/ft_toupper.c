#include <stdio.h>

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		ch = ch - 32;
	return (ch);
}

int	main(void)
{
	int		ch;

	ch = 'a';
	printf("ch was '%c' and now is '%c'\n", ch, ft_toupper(ch));
	ch = 'A';
	printf("ch was '%c' and now is '%c'\n", ch, ft_toupper(ch));
	ch = '0';
	printf("ch was '%c' and now is '%c'\n", ch, ft_toupper(ch));
	ch = '/';
	printf("ch was '%c' and now is '%c'\n", ch, ft_toupper(ch));
	ch = 'z';
	printf("ch was '%c' and now is '%c'\n", ch, ft_toupper(ch));
	ch = 'Z';
	printf("ch was '%c' and now is '%c'\n", ch, ft_toupper(ch));
	return (0);
}
