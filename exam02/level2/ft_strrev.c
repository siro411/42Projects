#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		len;
	char	tmp;
	int		i;

	while (str[len])
		len++;
	len--;
	i = 0;
	while (i < len)
	{
		tmp = str[len];
		str[len] = str[i];
		str[i] = tmp;
		len--;
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "helloworld";
	printf("%s", ft_strrev(str));
}