#include <stdio.h>
void	ft_ultimate_ft(int *********nbr)
{
	printf("%d\n", *********nbr);
}

void	ft_ft(int nbr)
{
	int		*ptr;
	int		**ptr1;
	int		***ptr2;
	int		****ptr3;
	int		*****ptr4;
	int		******ptr5;
	int		*******ptr6;
	int		********ptr7;
	int		*********ptr78;

	ptr = &nbr;
	ptr1 = &ptr;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &nbr;

}

int main()
{
	ft_ultimate_ft(42);
	return 0;
}
