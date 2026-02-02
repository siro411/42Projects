#include <unistd.h>

int	get_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	flag;
	int	res;
	int	digit;

	i = 0;
	flag = 1;
	res = 0;
	if (str_base > 16 || str_base < 2)
		return (0);
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i])
	{
		digit = get_digit(str[i]);
		if (digit == -1 || digit > str_base)
			break ;
		res = res * str_base + digit;
		i++;
	}
	return (flag * res);
}

#include <stdio.h>

int	main(void)
{
	const char	str[] = "10";

	printf("%d\n", ft_atoi_base(str, 2));
}
