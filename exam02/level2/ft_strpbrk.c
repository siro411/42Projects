#include <stdio.h>

// char	*ft_strpbrk(const char *s1, const char *s2)
// {
// 	unsigned char	seen[256] = {0};
// 	int				i;
// 	int				j;
// 	char			*res;

// 	res = (char *)s1;
// 	i = 0;
// 	j = 0;
// 	while (s2[j])
// 	{
// 		if (seen[(unsigned char)s2[j]] == 0)
// 		{
// 			seen[(unsigned char)s2[j]] = 1;
// 		}
// 		j++;
// 	}
// 	while (s1[i])
// 	{
// 		if (seen[(unsigned char)s1[i]] == 1)
// 		{
// 			return (res);
// 		}
// 		i++;
// 		res++;
// 	}
// 	return (NULL);
// }

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				return ((char *)&s1[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	// Declaring three strings
	char s1[] = "geeksforgeeks";
	char s2[] = "app";
	char s3[] = "kite";
	char *r, *t;

	// Checks for matching character
	// no match found
	r = ft_strpbrk(s1, s2);
	if (r != 0)
		printf("First matching character: %c\n", *r);
	else
		printf("Character not found");

	// Checks for matching character
	// first match found at "e"
	t = ft_strpbrk(s1, s3);
	if (t != 0)
		printf("\nFirst matching character: %c\n", *t);
	else
		printf("Character not found");

	return (0);
}