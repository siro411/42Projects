#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int	tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	printf("%d", a);
}
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int v1 = atoi(argv[1]);
		int v2 = atoi(argv[2]);
		if (v1 > 0 || v2 > 0)
			pgcd(v1, v2);
	}
	printf("\n");
	return (0);
}