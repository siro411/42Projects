/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:26:29 by anying            #+#    #+#             */
/*   Updated: 2025/11/15 11:26:29 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static char	*copy_word(const char *s, int start, size_t len)
{
	char	*word;

	word = (char *)malloc(sizeof(char) *(len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, s + start, len);
	word[len] = '\0';
	return (word);
}

static void	free_words(char **words, int j)
{
	while (j--)
		free(words[j]);
	free(words);
}

static int	fill_words(const char *s, char c, char **ret)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (!s[i])
			break ;
		k = i;
		while (s[i] && (s[i] != c))
			i++;
		ret[j] = copy_word(s, k, i - k);
		if (!ret[j])
		{
			free_words(ret, j);
			return (0);
		}
		j++;
	}
	ret[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	char	**ret;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!ret)
		return (NULL);
	if (!fill_words(s, c, ret))
		return (NULL);
	return (ret);
}
