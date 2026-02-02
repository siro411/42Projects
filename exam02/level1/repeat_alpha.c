#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int count;
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			count = 1;
			char c = argv[1][i];
			if (c >= 'a' && c <= 'z')
			{
				count = c - 'a' + 1;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				count = c - 'A' + 1;
			}
			while (count > 0)
			{
				ft_putchar(c);
				count--;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}