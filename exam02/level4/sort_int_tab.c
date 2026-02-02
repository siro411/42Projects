void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned	i;
	unsigned	j;
	int			tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int arr[] = {1, 9, 3, 5, 4};
	int i = 0;
	while (i < 5)
	{
		printf("%d ->", arr[i]);
		i++;
	}
	sort_int_tab(arr, 5);
	i = 0;
	printf("after\n");
	while (i < 5)
	{
		printf("%d ->", arr[i]);
		i++;
	}
}