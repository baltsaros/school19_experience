#include "ft_printf.h"

// REMOVE THIS FUNCTIONS LATER
static int	ft_base_control(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || (base[i] < 33
			&& base[i] > 126))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static void	ft_putnbr_un(int nb, unsigned int i, char *base)
{
	if (nb >= i)
	{
		ft_putnbr_un(nb / i, i, base);
		nb = nb % i;
	}
	if (nb < i)
		ft_putchar(base[nb]);
}

void	ft_putnbr_base_un(unsigned int nbr, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		++i;
	if (ft_base_control(base))
		ft_putnbr_un(nbr, i, base);
}

// int	main()
// {
// 	int		nbr;
// 	// char	*base;

// 	nbr = 1234678;
// 	ft_putnbr_base(nbr, "0123456789");
// 	ft_putchar('\n');
// 	ft_putnbr_base(nbr, "9876543210");
// 	ft_putchar('\n');
// 	ft_putnbr_base(nbr, "9876543");
// 	ft_putchar('\n');
// 	ft_putnbr_base(nbr, "01");
// 	ft_putchar('\n');
// 	ft_putnbr_base(nbr, "0123456789ABCDEF");
// 	ft_putchar('\n');
// 	ft_putnbr_base(nbr, "poneyvif");
// 	ft_putchar('\n');
// 	ft_putnbr_base(nbr, "abcdef");
// 	ft_putchar('\n');
// 	ft_putnbr_base(nbr, "helop");
// 	ft_putchar('\n');
// 	return (0);
// }
