#include <stdio.h>
int	main(void)
{
	// printf("TESTING +\n");
	// printf("%+d\n", 0);
	// printf("%+d\n", -1);
	// printf("%+d\n", 78);
	// printf("%+d\n", -101);
	// printf("%+i\n", 0);
	// printf("%+i\n", -1);
	// printf("%+i\n", 78);
	// printf("%+i\n", -101);
	// printf("\nTESTING 0\n");
	// printf("%01d\n", 0);
	// printf("%02d\n", -1); 
	// printf("%04d\n", -1); 
	// printf("%04d\n", 88);
	// printf("%03i\n", 14);
	// printf("%01u\n", -99);
	// printf("%05d\n", 17);
	// printf("%10x\n", -17);
	// printf("%05X\n", 100);
	// printf("%X\n", 100);
	// printf("%05p\n", 100);
	// printf("%15p\n", 100);
	// printf("%03c\n", 'c');
	// printf("%03s\n", "sa");
	// printf("%03%\n");
	// printf("\nTESING .\n");
	// printf("%.s\n", "t");
	// printf("%.3s\n", "t");
	// printf("%.6s\n", " - ");
	// printf("%.1c\n", 'c');
	// printf("%.6c\n", 'c');
	// printf("%.1d\n", 0);
	// printf("%.2d\n", -1);
	// printf("%.2d\n", 9);
	// printf("%.3i\n", 101);
	// printf("%.4i\n", -100);
	// printf("%.3u\n", 11);
	// printf("%.4u\n", 14);
	// printf("%.5u\n", -8);
	// printf("%.1u\n", -200);
	// printf("%.1x\n", 0);
	// printf("%.2x\n", 4);
	// printf("%.3X\n", 314);
	// printf("%.4x\n", -29);
	// printf("%.15X\n", -99);
	// printf("%.5p\n", -99);
	// printf("%.15p\n", -99);
	// printf("%.5%\n");
	// printf("\nTESTING -\n");
	// printf("%-1c\n", '0');
	// printf("%-2c\n", '1');
	// printf("%1s\n", "t");
	// printf("%-1s\n", "t");
	// printf("%-3s\n", "-");
	// printf("%2p\n", -1);
	// printf("%-2p\n", -1);
	// printf("%-3p\n", 77);
	// printf("%d\n", 0);
	// printf("%-1d\n", 0);
	// printf("%-2d\n", -1);
	// printf("%-4d\n", 15);
	// printf("%-1u\n", 0);
	// printf("%-2u\n", -1);
	// printf("%-6u\n", -16);
	// printf("%-1x\n", 0);
	// printf("%-3x\n", -1);
	// printf("%-5x\n", 115);
	// printf("%-2X\n", -5);
	// printf("%-3X\n", 0);
	// printf("%-1X\n", 89);
	// printf("%-15X\n", 89);
	// printf("%-2%\n", 89);
	// printf("\nTESTING #\n");
	// printf("%#c\n", 'c');
	// printf("%#s\n", "test");
	// printf("%#d\n", -3);
	// printf("%#i\n", -3);
	// printf("%#u\n", 3);
	// printf("%#x\n", 0);
	// printf("%#x\n", -1);
	// printf("%x\n", -1);
	// printf("%#x\n", 9);
	// printf("%#x\n", 54);
	// printf("%#x\n", -93);
	// printf("%#X\n", 0);
	// printf("%#X\n", -5);
	// printf("%X\n", -5);
	// printf("%#X\n", -111);
	// printf("%#X\n", 222);
	// printf("%#X\n", 13);
	// printf("%#p\n", 13);
	// printf("%#%\n");
	// printf("\nTESTING (space)\n");
	// printf("% c\n", 'c');
	// printf("% s\n", "test");
	// printf("% 1s\n", "tst");
	// printf("%d\n", 0);
	// printf("% d\n", 0);
	// printf("%  2d\n", 0);
	// printf("% d\n", 56);
	// printf("% d\n", -87);
	// printf("% i\n", -1);
	// printf("% i\n", 13);
	// printf("% i\n", -77);
	// printf("% i\n", 999);
	// printf("% 3u\n", 333);
	// printf("% u\n", 3);
	// printf("% p\n", 999);
	// printf("% x\n", 999);
	// printf("% X\n", 999);
	// printf("% %\n");
	// printf("\nTEST END\n");
	// return (0);
}

// test code for c tutor
// #include <stdio.h>
// #include <stdarg.h>

// typedef struct s_par
// {
//     int    zero;
//     int    minus;
//     int    dot;
//     int    space;
//     int    plus;
//     int    sharp;
//     int    width;
//     int    type;
// }    t_par;

// static void    ft_set_params(t_par *params)
// {
//     params->zero = 1;
//     params->minus = 0;
//     params->dot = -1;
//     params->space = 0;
//     params->plus = 0;
//     params->sharp = 0;
//     params->width = 4;
//     params->type = 99;
// }

// void    ft_putchar(char c, int *r)
// {
//     write(1, &c, 1);
//     ++(*r);
// }

// void    ft_output_char(char c, t_par *params, int *r)
// {
//     if (params->width > 0)
//         (*r) += params->width;
//     else
//         ++(*r);
//     if (params->minus > 0)
//     {
//         write(1, &c, 1);
//         while (params->width - 1 > 0)
//         {
//             write(1, " ", 1);
//             --params->width;
//         }
//     }
//     else if (params->zero > 0)
//     {
//         while (params->width - 1 > 0)
//         {
//             write(1, " ", 1);
//             --params->width;
//         }
//         write(1, &c, 1);
//     }
//     else
//         write(1, &c, 1);
// }

// static void    *ft_output(va_list arg, t_par *params, int *r)
// {
//     if (params->type == 'c')
//       ft_output_char(va_arg(arg, unsigned int), params, r);
// }

// int    ft_printf(const char *str, ...)
// {
//     va_list    arg;
//     t_par    params;
//     int        r;

//     va_start(arg, str);
//     r = 0;
//     while (*str)
//     {
//         if (*str == '%')
//         {
//             ++str;
//             ft_set_params(&params);
//             ft_output(arg, &params, &r);
//         }
//         else
//             ft_putchar(*str, &r);
//         ++str;
//     }
//     va_end(arg);
//     return (r);
// }

// int main(void)
// {
//   ft_printf("  %04c\n", 'a');
//   return (0);
// }