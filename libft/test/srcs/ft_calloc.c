#include <stdlib.h> 
#include <unistd.h>

void	*ft_calloc(size_t num, size_t size)
{
	int	*ptr;
	unsigned int	i;

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
