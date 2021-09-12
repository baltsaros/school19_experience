#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    milieu(int x, int y)
{
    int    i;
    int    cmp;

    if (y > 1)
    {
        cmp = 0;
        while (cmp < (y - 2))
        {
            ft_putchar('\n');
            ft_putchar('|');
            i = 0;
            while (i < (x - 2))
            {
                ft_putchar(' ');
                i ++;
            }
            cmp ++;
        }
        if (x > 1 && y > 1)
        {
            ft_putchar('\n');
            ft_putchar('|');
        }
    }
}

void    fin(int x, int y)
{
    int    cmp;

    if (x > 1 && y > 1)
    {
        ft_putchar('\n');
        ft_putchar('o');
    }
    cmp = 0;
    while (cmp < (x - 2))
    {
        ft_putchar('-');
        cmp ++;
    }
    if (y > 1)
    {
        ft_putchar('\n');
        ft_putchar('o');
    }
}

void    rush(int x, int y)
{
    if (x > 1 && y == 1)
    {
        ft_putchar('o');
    }
    fin(x, y);
    milieu(x, y);
    fin(x, y);
    if (x == 1 && y == 1)
    {
        ft_putchar('o');
    }
    if (x > 1 && y == 1)
    {
        ft_putchar('o');
    }
}

int    main(void)
{
    rush(1, 5);
}
