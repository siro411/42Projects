#include <unistd.h>

void	ft_print_nbr(int nbr)
{
	char	c;

	if (nbr >= 10)
	{
		ft_print_nbr(nbr / 10);
	}
	c = '0' + nbr;
	write(1, &c, 1);
}

int	main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_print_nbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}