#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		int v1 = atoi(argv[1]);
		int v2 = atoi(argv[3]);
		char op = argv[2][0];

		if (op == '+')
			printf("%d", v1 + v2);
		else if (op == '-')
			printf("%d", v1 - v2);
		else if (op == '*')
			printf("%d", v1 * v2);
		else if (op == '/')
			printf("%d", v1 / v2);
		else if (op == '%')
			printf("%d", v1 % v2);
	}
	printf("\n");
	return (0);
}