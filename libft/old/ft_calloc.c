#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	int		*ptr;
	size_t	i;

	i = 0;
	ptr = (int *)malloc(num * size);
	if (NULL == ptr)
		return (NULL);
	while (i < num)
	{
		ptr[i] = 0;
		++i;
	}
	return (ptr);
}

int	main(void)
{
	unsigned int	i;
	unsigned int	num;
	int				*ptr;

	i = 0;
	num = 5;
	ptr = ft_calloc(num, sizeof(int));
	while (i < num)
	{
		write(1, &ptr[i], 1);
		write(1, "\n", 1);
		++i;
	}
	free(ptr);
	return (0);
}
