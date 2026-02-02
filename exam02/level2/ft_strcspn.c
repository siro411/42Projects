#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (i);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	int size;

	// initializing strings
	char str1[] = "geeksforgeeks";
	char str2[] = "kfc";

	// using strcspn() to calculate initial chars
	// before 1st matching chars.
	size = strcspn(str1, str2);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("%d\n", size);
}