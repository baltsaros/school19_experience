int        ft_str_is_alpha(char *str)
{
    while (*str != '\0')
    {
        if ((*str < 'A') || (*str > 'z'))
        {
            return 0;
        }
        if ((*str <= 'Z' ) || (*str >= 'a'))
        {
            *str++;
        }
        else
        {
            return (0);
        }
    }    
    return (1);
}

int        main()
{
    char    *str;

    str = "tEst";
    ft_str_is_alpha(str);
}