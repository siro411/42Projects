#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	int		j;
	int		found;

	i = 0;
	while (s[i])
	{
		j = 0;
		found = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	int len;
	const char str1[] = "ABCDEFG019874";
	const char str2[] = "ABCD";

	len = strspn(str1, str2);

	printf("Length of initial segment matching %d\n", len);

	return (0);
}