#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base_control(char *base)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (base[j] == '\0'|| base[j + 1] == '\0' || base[j] == '-'
		|| base[j] == '+' || base[j] == ' ')
		return (0);
	while (base[j])
	{
		if (base[j] == base[i])
			return (0);
		++j;
		i = j + 1;
	}
	return (1);
}

void	ft_putnbr(int nbr, int i)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 0)
	{
		ft_putnbr(nbr / i, i);
		nbr = nbr % i;
		if (nbr < 10)
			ft_putchar(nbr + 48);
		if (nbr >= 10)
			ft_putchar(nbr + 55);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	if (nbr == 0)
		return ;
	i = 0;
	while (base[i])
		++i;
	if (ft_base_control(base))
		ft_putnbr(nbr, i);
}

int	main()
{
	int		nbr;
	char	*base;

	nbr = 123456789;
	ft_putnbr_base(nbr, "bcdefghjk");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "01");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "poneyvif");
	ft_putchar('\n');
	return (0);
	//base = "0123456789"
	//base = "01"
	//base = "0123456789ABCDEF"
	//base = "poneyvif"
}
