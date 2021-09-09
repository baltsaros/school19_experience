#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	printf("%d\n", *a);
	printf("%d\n", *b);
}

int main()
{
	int a;
	int b;
	int div;
	int mod;
	
	a = 44;
	b = 5;
	div = a / b;
	mod = a % b;
	ft_ultimate_div_mod(&div, &mod);
	return 0;
}