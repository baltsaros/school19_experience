#include <unistd.h>
#include "display_file.h"

int		main(int argc, char *argv[])
{
	if (argc < 2)
		ft_putstr_fd(2, ERR_1);
	else if (argc > 2)
		ft_putstr_fd(2, ERR_2);
	else 
	{
		if (display_file(argv[1]) != 1)
			ft_putstr_fd(2, ERR_3);
		else
			return (1);
	}
	return (0);
}
