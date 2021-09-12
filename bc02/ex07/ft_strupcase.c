char  *ft_strupcase(char *str)
{
    while (*str != '\0')
    {
        if ((*str >= 97) && (*str <= 122))
        {
            *str = *str - 32;
        }
        *str++;
    }
    return (*str);
}

int        main()
{
    char    str[] = "1aesz";

    printf("first %s\n", str);
    *ft_strupcase(str);
    printf("third %s\n", str);
    return (0);
}
