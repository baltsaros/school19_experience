#include <unistd.h>
int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (str[j] == '\0'|| str[j + 1] == '\0')
		return ;
	while (str[j])
	{
		if ()
		++i;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr < 0)
		nbr = -nbr;
	if (base == "0123456789")
		ft_base_deci(nbr);
	if (base == "01")
		ft_base_binary(nbr);
	if (base == "0123456789ABCDEF")
		ft_base_hexadec(nbr);
	if (base == "poneyvif")
		ft_base_oct(nbr);
}

int	main()
{
	int		nbr;
	//char	*base;

	nbr = 400;
	ft_putnbr_base(nbr, "0123456789");
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
