#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
  res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

void	ft_print_hex(unsigned int num)
{
	char	*hex_digits = "0123456789abcdef";

	if (num >= 16)
		ft_print_hex(num / 16);
	write(1, &hex_digits[num % 16], 1);
}

int	main(int argc, char *argv[])
{
	int num;
  num = 0;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		ft_print_hex(num);
	}
	write(1, "\n", 1);
	return (0);
}