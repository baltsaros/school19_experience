#include <stdio.h>
void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int main()
{
	int		nbr;
	int		*ptr;
	int		**ptr1;
	int		***ptr2;
	int		****ptr3;
	int		*****ptr4;
	int		******ptr5;
	int		*******ptr6;
	int		********ptr7;

	nbr = 42;
	ptr = &nbr;
	ptr1 = &ptr;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;

	ft_ultimate_ft(&ptr7);
	printf("%d\n", nbr);
	return 0;
}
