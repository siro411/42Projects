#include <stdio.h>
#include <stdlib.h>

int	word_count(char *str)
{
	int	i;
	int	word_num;

	i = 0;
	word_num = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			word_num += 1;
			while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
				i++;
		}
	}
	return (word_num);
}

char	*fill_words(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**res;
	int		len;
	int		i;
	int		start;
	int		end;
	int		k;

	len = word_count(str);
	i = 0;
	k = 0;
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	while (k < len)
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			i++;
		end = i;
		res[k] = fill_words(str, start, end);
		if (!res[k])
		{
			while (k > 0)
				free(res[--k]);
			free(res);
			return (NULL);
		}
		k++;
	}
	res[k] = NULL;
	return (res);
}

int	main(void)
{
	int i = 0;
	char str[] = "You hate people! But I love gatherings. Isn't it ironic?";
	// char str[] = "You hate people!";
	char **res = ft_split(str);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}