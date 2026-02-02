#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			char c = argv[1][i];
			if (c >= 'a' && c <= 'z')
			{
				c = ('z' - c) + 'a';
			}
			else if (c >= 'A' && c <= 'Z')
			{
				c = ('Z' - c) + 'A';
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}