#include <stdio.h>

void    ft_sort_int_tab(int *tab, int size)
{
    int        i;
    int        tmp;

    i = 0;
    while (i < size)
    {
        if (tab[i] > tab[size - 1])
        {
            tmp = tab[i];
            tab[i] = tab[size - 1];
            tab[size - 1] = tmp;
            i = 0;
            --size;
        }
        else
        {
            ++i;
        }
    }
}

int        main()
{
    int        tab[8] = { 4, 9, 15, 7, 0, 35, 4, 3 };
    int        j = 0;

    ft_sort_int_tab(tab, 8);
    while (tab[j] != '\0')
    {
        printf("%d ", tab[j]);
        ++j;
    }
    return (0);
}