// int	is_power_of_2(unsigned int n)
// {
// 	if (n == 0)
// 		return (0);
// 	while (n > 1)
// 	{
// 		if (n % 2)
// 			return (0);
// 		n = n / 2;
// 	}
// 	return (1);
// }

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n & (n - 1) == 0)
		return (1);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	printf("%d is a power of 2? %d\n", 123, is_power_of_2(123));
	printf("%d is a power of 2? %d\n", 8, is_power_of_2(8));
}