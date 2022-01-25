test code for c tutor

#include <stdio.h>
#include <stdarg.h>

typedef struct s_par
{
    int    zero;
    int    minus;
    int    dot;
    int    space;
    int    plus;
    int    sharp;
    int    width;
    int    type;
}    t_par;

static void    ft_set_params(t_par *params)
{
    params->zero = 1;
    params->minus = 0;
    params->dot = -1;
    params->space = 0;
    params->plus = 0;
    params->sharp = 0;
    params->width = 4;
    params->type = 99;
}

void    ft_putchar(char c, int *r)
{
    write(1, &c, 1);
    ++(*r);
}

void    ft_output_char(char c, t_par *params, int *r)
{
    if (params->width > 0)
        (*r) += params->width;
    else
        ++(*r);
    if (params->minus > 0)
    {
        write(1, &c, 1);
        while (params->width - 1 > 0)
        {
            write(1, " ", 1);
            --params->width;
        }
    }
    else if (params->zero > 0)
    {
        while (params->width - 1 > 0)
        {
            write(1, " ", 1);
            --params->width;
        }
        write(1, &c, 1);
    }
    else
        write(1, &c, 1);
}

static void    *ft_output(va_list arg, t_par *params, int *r)
{
    if (params->type == 'c')
      ft_output_char(va_arg(arg, unsigned int), params, r);
}

int    ft_printf(const char *str, ...)
{
    va_list    arg;
    t_par    params;
    int        r;

    va_start(arg, str);
    r = 0;
    while (*str)
    {
        if (*str == '%')
        {
            ++str;
            ft_set_params(&params);
            ft_output(arg, &params, &r);
        }
        else
            ft_putchar(*str, &r);
        ++str;
    }
    va_end(arg);
    return (r);
}

int main(void)
{
  ft_printf("  %04c\n", 'a');
  return (0);
}

#include <stdio.h>
#include <stdarg.h>

static int    ft_nbrlen(int nbr)
{
    int    len;

    len = 0;
    if (nbr <= 0)
        ++len;
    while (nbr)
    {
        nbr = nbr / 10;
        ++len;
    }
    return (len);
}

void    ft_putchar(char c, int *r)
{
    write(1, &c, 1);
    ++(*r);
}

static int    ft_width(int *width)
{
    if (*width > 0)
    {
        --(*width);
        return (1);
    }
    return (0);
}

int main()
{
  int nbr;
  int width;
  int r;
  
  nbr = 5;
  width = 4;
  r = 0;
  width = width - ft_nbrlen(nbr);
  while (ft_width(&width) && nbr >= 0)
    ft_putchar('o', &r);
  return (0);
}



#include <stdio.h>
#include <stdarg.h>

typedef struct s_par
{
    int    zero;
    int    minus;
    int    dot;
    int    space;
    int    plus;
    int    sharp;
    int    width;
    int    type;
}    t_par;

static void    ft_set_params(t_par *params)
{
    params->zero = 0;
    params->minus = 0;
    params->dot = 5;
    params->space = 0;
    params->plus = 0;
    params->sharp = 0;
    params->width = 0;
    params->type = 0;
}

void    ft_putchar(char c, int *r)
{
    write(1, &c, 1);
    ++(*r);
}

static int    ft_decrease(int *width)
{
    if (*width > 0)
    {
        --(*width);
        return (1);
    }
    return (0);
}


void    ft_output_nbr(t_par *params, int nbr, int *r)
{
    params->width = params->width - 1;
    if (params->plus && nbr >= 0)
        --params->width;
    while (params->space && ft_decrease(&params->width))
        ft_putchar(' ', r);
    while (!params->zero && ft_decrease(&params->width))
        ft_putchar(' ', r);
    if (params->plus && nbr >= 0)
        ft_putchar('+', r);
    else if (params->space && nbr >= 0)
        ft_putchar(' ', r);
    if (nbr < 0)
        ft_putchar('-', r);
    while (params->zero && ft_decrease(&params->width))
        ft_putchar('0', r);
    params->dot = params->dot - 1;
    while (ft_decrease(&params->dot))
        ft_putchar('0', r);
    while (params->minus && ft_decrease(&params->width))
        ft_putchar(' ', r);
}

int    ft_printf(const char *str, ...)
{
    va_list    arg;
    t_par    params;
    int        r;

    va_start(arg, str);
    r = 0;
    while (*str)
    {
        if (*str == '%')
        {
            ++str;
            ft_set_params(&params);
            ft_output_nbr(&params, va_arg(arg, int), &r);
        }
       ft_putchar(*str, &r);
        ++str;

    }
    va_end(arg);
    return (r);
}

int main(void)
{
  ft_printf("%5c\n", 'a');
  return (0);
}