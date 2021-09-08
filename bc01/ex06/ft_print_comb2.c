#include <unistd.h>

void    ft_putspace(void)
{
    write(1, " ", 1);
}
void    ft_putcomma(void)
{
	write(1, ",", 1);
}
void    ft_putchar_ab(char a, char b)
{
    write(1, &a, 1);
    write(1, &b, 1);
}
void    ft_putchar_cd(char c, char d)
{
    write(1, &c, 1);
    write(1, &d, 1);
}


void ft_put_comb2(void)
{
    char a, b, c, d;

    a = '0' - 1;
    while(a++ <= '9')
    {
        b = a - 1;
        while(b++ < '8')
        {
			d++;
            c = a - 1;
			while(c++ < '9')
			{
				d = c - 1;
				while(d++ < '9')
				{
					if(a == 9 && b == 8 && c == 9 && d == 9)
					{
						ft_putspace();
					}
					ft_putchar_ab(a, b);
					ft_putspace();
					ft_putchar_cd(c, d);
					ft_putcomma();
					ft_putspace();
				}
			}
        }
    }
}

int		main()
{
	ft_put_comb2();
	return 0;
}