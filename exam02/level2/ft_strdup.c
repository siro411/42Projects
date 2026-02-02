#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	while (src[len])
	{
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char s[] = "hello";
	printf("%s", ft_strdup(s));
}