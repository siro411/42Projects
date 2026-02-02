#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*res;
	long	n;
	int		len;
	long	tmp;

	n = (long)nbr;
	len = 0;
	if (nbr < 0)
	{
		len++;
	}
	tmp = n;
	while (tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n)
	{
		res[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}

int	main(void)
{
	printf("%s\n", ft_itoa(0));           // 0
	printf("%s\n", ft_itoa(42));          // 42
	printf("%s\n", ft_itoa(-42));         // -42
	printf("%s\n", ft_itoa(-2147483648)); // -2147483648 (INT_MIN)
	printf("%s\n", ft_itoa(2147483647));  // 2147483647 (INT_MAX)
	return (0);
}