#include <stdio.h>

void    ft_rev_int_tab(int *tab, int size)
{
    int        tmp;
    int        i;

    i = 0;
    while (i < size)
    {
        tmp = tab[i];
        tab[i] = tab[size - 1];
        tab[size - 1] = tmp;
        ++i;
        --size;
    }
}

int        main()
{
    int        tab[5] = { 1, 2, 3, 4, 5 };
    int        j = 0;

    ft_rev_int_tab(tab, 5);
    while (j != 5)
    {
        printf("%d ", tab[j]);
        ++j;
    }
    return (0);
}
