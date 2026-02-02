#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*res;
	int	step;

	i = 0;
	if (start <= end)
	{
		len = end - start + 1;
		step = 1;
	}
	else
	{
		len = start - end + 1;
		step = -1;
	}
	res = (int *)malloc(len * sizeof(int));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = start;
		i++;
		start += step;
	}
	return (res);
}

int	main(void)
{
	int *arr;

	int i;
	// i = 0;
	// arr = ft_range(1, 3);

	// while (arr[i])
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	// arr = ft_range(-1, 2);
	// i = 0;
	// int len = 4;
	// while (i < len)
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	// arr = ft_range(0, 0);
	// i = 0;

	// while (arr[i])
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	arr = ft_range(0, -3);
	i = 0;

	while (arr[i])
	{
		printf("%d\n", arr[i]);
		i++;
	}
}