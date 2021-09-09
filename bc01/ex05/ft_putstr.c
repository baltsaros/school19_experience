#include <unistd.h>

void	ft_putstr(char *str)
{
	write(1, str, sizeof(str));
}

int		main()
{
	ft_putstr("test");
	return 0;
}

/*
void	ft_putstr(char *str)
{
	str = " testtwo";
	write(1, str, sizeof(str));
}

int		main()
{
	char	*str;

	str = "test";
	write(1, str, sizeof(str));
	ft_putstr(str);
	return 0;
}
/*