#include <stdio.h>

int	ft_tolower(int ch)
{
	if (ch >= 65 && ch <= 90)
		ch = ch + 32;
	return (ch);
}

int	main(void)
{
	int		ch;

	ch = 'a';
	printf("ch was '%c' and now is '%c'\n", ch, ft_tolower(ch));
	ch = 'A';
	printf("ch was '%c' and now is '%c'\n", ch, ft_tolower(ch));
	ch = '1';
	printf("ch was '%c' and now is '%c'\n", ch, ft_tolower(ch));
	ch = '~';
	printf("ch was '%c' and now is '%c'\n", ch, ft_tolower(ch));
	ch = 'z';
	printf("ch was '%c' and now is '%c'\n", ch, ft_tolower(ch));
	ch = 'Z';
	printf("ch was '%c' and now is '%c'\n", ch, ft_tolower(ch));
	return (0);
}
