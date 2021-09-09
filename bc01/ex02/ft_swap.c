#include <stdio.h>
void	ft_swap(int *a, int *b)
{
	int		c;

	c = *b;
	*b = *a;
	*a = c;
}

int main()
{
	int		a;
	int		b;

	a = 42;
	b = 19;

	printf("%d\n", a);
	printf("%d\n", b);
	ft_swap(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}
