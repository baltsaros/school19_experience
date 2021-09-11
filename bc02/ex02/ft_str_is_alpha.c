int        ft_str_is_alpha(char *str)
{
    while (*str != '\0')
    {
        if ((*str < 65) || (*str > 122))
        {
            return 0;
        }
        if ((*str <= 90 ) || (*str >= 97))
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