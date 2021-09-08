#include <unistd.h>
void    ft_putchar(char i)
{
    write(1, &i, 1);
}

void    ft_writechar(char a, char b, char c, int end)
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

void ft_print_comb(void)
{
    char a, b, c;
    int end;

    a = '0';
    while(a <= '7')
    {
        b = a + 1;
        while(b <= '8')
        {
            c = b + 1;
            while(c <= '9')
            {
                if(a == '7' && b == '8' && c == '9')
                {
                    end = 1;
                }
                ft_writechar(a, b, c, end);
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