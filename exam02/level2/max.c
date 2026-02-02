int	max(int *tab, unsigned int len)
{
	int	max;

	if (!len)
	{
		return (0);
	}
	max = tab[--len];
	while (len--)
	{
		if (max < tab[len])
		{
			max = tab[len];
		}
	}
	return (max);
}

#include <stdio.h>

int	main(void)
{
	int tab[] = {11, 2, 3, 4, 5, 10};
	printf("%d\n", max(tab, 6));
}