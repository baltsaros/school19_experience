#include <unistd.h>

void    ft_print_alphabet(void)
{
    write(1, "abcdefghijklmnopqrstuvwxyz\n", 27);
}

int     main()
{
    ft_print_alphabet();
    return 0;
}