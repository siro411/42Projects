int	ft_atoi(const char *str)
{
	int		i;
	int		flag;
	long	res;

	i = 0;
	flag = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (int)(flag * res);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("-123"));
	printf("%d\n", ft_atoi("+123"));
	printf("%d\n", ft_atoi("1231121"));

	return (0);
}