#include <unistd.h>

int	ft_atoi(char *s)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

int	isPrime(int num)
{
	int	i;

	if (num <= 1)
		return (0);
	if (num == 2 || num == 3)
		return (1);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putnum(int num)
{
	char	c;

	if (num > 9)
	{
		ft_putnum(num / 10);
	}
	c = num % 10 + 48;
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int max;
	int sum = 0;
	int i = 0;

	if (argc == 2 && argv[1][0] != '-')
	{
		max = ft_atoi(argv[1]);
		while (i <= max)
		{
			if (isPrime(i))
			{
				sum += i;
			}
			i++;
		}
		ft_putnum(sum);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "0", 1);
		write(1, "\n", 1);
	}
}