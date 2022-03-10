#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	printf("TESTING %%d with flags...........\n");
	ft_printf("FT | TEST 01 | %d \n", 5);
	printf("OR | TEST 01 | %d \n", 5);
	ft_printf("FT | TEST 02 | %d\n", ft_printf("%d\n", 5));
	printf("OR | TEST 02 | %d\n", printf("%d\n", 5));
	ft_printf("FT | TEST 03 | %d\n", -115);
	printf("OR | TEST 03 | %d\n", -115);
	ft_printf("FT | TEST 04 | %d%d%d\n", -115, 0 , 999);
	printf("OR | TEST 04 | %d%d%d\n", -115, 0 , 999);
	ft_printf("FT | TEST 05 | %d %d %d\n", -215, 0, 6666);
	printf("OR | TEST 05 | %d %d %d\n", -215, 0, 6666);
	ft_printf("FT | TEST 06 | %d\n", ft_printf("\n%d %d %d\n", -215, 0, 6666));
	printf("OR | TEST 06 | %d\n", printf("\n%d %d %d\n", -215, 0, 6666));

	printf("TESTING %i with flags...........\n");
	ft_printf("FT | TEST 01 | %i \n", 5);
	printf("OR | TEST 01 | %i \n", 5);
	ft_printf("FT | TEST 02 | %i\n", ft_printf("%i\n", 5));
	printf("OR | TEST 02 | %i\n", printf("%i\n", 5));
	ft_printf("FT | TEST 03 | %i\n", -115);
	printf("OR | TEST 03 | %i\n", -115);

	printf("TESTING %%c with flags...........\n");
	ft_printf("FT | TEST 1 | %c\n", 'a');
	printf("OR | TEST 1 | %c\n", 'a');
	ft_printf("FT | TEST 2 | %c %c %c\n", 'a', 'b', 'c');
	printf("OR | TEST 2 | %c %c %c\n", 'a', 'b', 'c');
	ft_printf("FT | TEST 3 | %c%c%c\n", 'a', 'b', 'c');
	printf("OR | TEST 3 | %c%c%c\n", 'a', 'b', 'c');
	ft_printf("FT | TEST 4 | %d\n", ft_printf("%c %c %c\n", 'a', 'b', 'c'));
	printf("OR | TEST 4 | %d\n", printf("%c %c %c\n", 'a', 'b', 'c'));
	
	printf("TESTING %%s with flags...........\n");
	ft_printf("FT | TEST 1 | %s\n", "test");
	printf("OR | TEST 1 | %s\n", "test");
	ft_printf("FT | TEST 2 | %s%s%s\n", "one", "two", "three");
	printf("OR | TEST 2 | %s%s%s\n", "one", "two", "three");
	ft_printf("FT | TEST 3 | %s %s %s\n", "one", "two", "three");
	printf("OR | TEST 3 | %s %s %s\n", "one", "two", "three");
	ft_printf("FT | TEST 4 | %d\n", ft_printf("%s %s %s\n", "one", "two", "three"));
	printf("OR | TEST 4 | %d\n", printf("%s %s %s\n", "one", "two", "three"));
	ft_printf("FT | TEST 11 | %s\n", NULL);
	printf("OR | TEST 11 | %s\n", NULL);
	ft_printf("FT | TEST 12 | %d\n", ft_printf("%s\n", NULL));
	printf("OR | TEST 12 | %d\n", printf("%s\n", NULL));
	
	printf("TESTING %%u with flags...........\n");
	ft_printf("FT | TEST 1 | %u\n", 3);
	printf("OR | TEST 1 | %u\n", 3);
	ft_printf("FT | TEST 2 | %u\n", -3);
	printf("OR | TEST 2 | %u\n", -3);
	ft_printf("FT | TEST 3 | %u%u%u\n", 1, 2, 3);
	printf("OR | TEST 3 | %u%u%u\n", 1, 2, 3);
	ft_printf("FT | TEST 4 | %u %u %u\n", 11, 22, -33);
	printf("OR | TEST 4 | %u %u %u\n", 11, 22, -33);
	ft_printf("FT | TEST 5 | %u\n", ft_printf("%u %u %u\n", 11, 22, -33));
	printf("OR | TEST 5 | %u\n", printf("%u %u %u\n", 11, 22, -33));

	printf("TESTING %%x with flags...........\n");
	ft_printf("FT | TEST 1 | %x\n", 177);
	printf("OR | TEST 1 | %x\n", 177);
	ft_printf("FT | TEST 2 | %x\n", -123);
	printf("OR | TEST 2 | %x\n", -123);
	ft_printf("FT | TEST 3 | %x\n", 0);
	printf("OR | TEST 3 | %x\n", 0);
	ft_printf("FT | TEST 4 | %x%x%x\n", 111, 2222, 33333);
	printf("OR | TEST 4 | %x%x%x\n", 111, 2222, 33333);
	ft_printf("FT | TEST 5 | %x %x %x\n", 0, -555, 888);
	printf("OR | TEST 5 | %x %x %x\n", 0, -555, 888);
	ft_printf("FT | TEST 6 | %d\n", ft_printf("%x %x %x\n", 0, -555, 888));
	printf("OR | TEST 6 | %d\n", printf("%x %x %x\n", 0, -555, 888));

	printf("TESTING %%X with flags...........\n");
	ft_printf("FT | TEST 1 | %X\n", 177);
	printf("OR | TEST 1 | %X\n", 177);
	ft_printf("FT | TEST 2 | %X\n", -123);
	printf("OR | TEST 2 | %X\n", -123);
	ft_printf("FT | TEST 3 | %X\n", 0);
	printf("OR | TEST 3 | %X\n", 0);
	ft_printf("FT | TEST 4 | %X%X%X\n", 111, 2222, 33333);
	printf("OR | TEST 4 | %X%X%X\n", 111, 2222, 33333);
	ft_printf("FT | TEST 5 | %X %X %X\n", 0, -555, 888);
	printf("OR | TEST 5 | %X %X %X\n", 0, -555, 888);
	ft_printf("FT | TEST 6 | %d\n", ft_printf("%X %X %X\n", 0, -555, 888));
	printf("OR | TEST 6 | %d\n", printf("%X %X %X\n", 0, -555, 888));

	printf("TESTING %%p with flags...........\n");
	ft_printf("FT | TEST 1 | %p\n", 177);
	printf("OR | TEST 1 | %p\n", 177);
	ft_printf("FT | TEST 2 | %p\n", -123);
	printf("OR | TEST 2 | %p\n", -123);
	ft_printf("FT | TEST 3 | %p\n", 0);
	printf("OR | TEST 3 | %p\n", 0);
	ft_printf("FT | TEST 4 | %p%p%p\n", 111, 2222, 33333);
	printf("OR | TEST 4 | %p%p%p\n", 111, 2222, 33333);
	ft_printf("FT | TEST 5 | %p %p %p\n", 0, -555, 888);
	printf("OR | TEST 5 | %p %p %p\n", 0, -555, 888);
	ft_printf("FT | TEST 6 | %d\n", ft_printf("%p %p %p\n", 0, -555, 888));
	printf("OR | TEST 6 | %d\n", printf("%p %p %p\n", 0, -555, 888));

	printf("TESTING %% with flags...........\n");
	ft_printf("FT | TEST 1 | %%%%%%\n");
	printf("OR | TEST 1 | %%%%%%\n");
	ft_printf("FT | TEST 2 | %% %% %%\n");
	printf("OR | TEST 2 | %% %% %%\n");
	return (0);
}