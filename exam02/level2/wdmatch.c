#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int i;
	int j;
	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		if (argv[1][i] == '\0')
		{
			ft_putstr(argv[1]);
		}
	}
	write(1, "\n", 1);
	return (0);
}