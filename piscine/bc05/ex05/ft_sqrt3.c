int	ft_extraction(nb, i)
{
	int		dif;

	if (i < nb)
		dif = nb - ft_extraction(nb, i + 2);
	if (dif == 0)
		return (1);
	else
		return (0);
}
int	ft_sqrt(int nb)
{

	if (ft_extraction(nb, 1))
		return (1);
	if (nb == 1)
		return (1);
	else
		return (0);
}


#include <stdio.h>
int	main()
{
	printf("%d\n", ft_sqrt(-2));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(2147395600));
}