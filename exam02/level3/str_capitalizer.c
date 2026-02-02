#include <unistd.h>

void	str_capitalizer(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			c = c - 'A' + 'a';
		}
		if (c >= 'a' && c <= 'z')
		{
			if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t')
			{
				c = c - 'a' + 'A';
			}
		}
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int i;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}