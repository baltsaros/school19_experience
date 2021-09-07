#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_write_comb(char a, char b, char c, int end)
{
    ft_putchar(a);
    ft_putchar(b);
    ft_putchar(c);

    if(end != 1)
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
	else
	ft_putchar('\n');
}

void    ft_print_comb(void)
{
    char a, b, c;
    int end;

    a = '0';
    while(a <= '7')
    {
        b = '1';
        while(b <= '8')
        {
            c = '2';
            while(c <= '9')
            {
                if( a == '7' && b == '8' && c == '9')
                {
                    end = 1;
                }
                    ft_write_comb(a, b, c, end);
                c++;
            }
            b++;
        }
        a++;
    }
}
int     main()
{
    ft_print_comb();
    return 0;
}