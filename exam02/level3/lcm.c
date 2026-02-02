unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	tmp;
	unsigned int	swap;
	unsigned int	n;

	if (!a || !b)
		return (0);
	n = a;
	tmp = b;
	while (tmp)
	{
		swap = tmp;
		tmp = n % tmp;
		n = swap;
	}
	return ((a / n) * b);
}

#include <stdio.h>

int	main(void)
{
	printf("lcm is %d", lcm(42, 12));
}