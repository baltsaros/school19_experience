#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = (char *) addr;
	if (size == 0)
		return (0);
	while (s[i])
	{
		if ((i + 1) % 16 == 0)
			write(1, "\n", 1);
		
	}

}

int		main(void)
{
	char	str[] = "Bonjour les aminches... c est fou\ntout\fce qu on peut faire avec...print_memory...lol\vlol. .";

	ft_print_memory(str, 91);
	return (0);
}