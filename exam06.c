#include <stdio.h>

int		main()
{
	char str[] = "abcdtt";
	int i;
	int j;

	i = 0;
	j = sizeof(str);

	char temp[j];

	j = j - 1;
	while (j != 0)
	{
		temp[i] = str[j - 1];
		i++;
		j--;
	}

	printf("str %s\n", str);
	printf("temp %s\n", temp);

	j = sizeof(str) - 1;
	i = 0;
	while (j != 0)
	{
		str[i] = temp[i];
		i++;
		j--;
	}
	printf("str %s\n", str);
	printf("temp %s\n", temp);
	return (0);
}
