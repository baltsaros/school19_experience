#include <unistd.h>

void    ft_print_reverse_alphabet(void)
{
    write(1, "zyxwvutsrqponmlkjihgfedcba\n", 27);
}

int     main()
{
    ft_print_reverse_alphabet();
    return 0;
}