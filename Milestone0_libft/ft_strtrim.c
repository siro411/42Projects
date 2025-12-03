/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:26:29 by anying            #+#    #+#             */
/*   Updated: 2025/11/15 11:26:29 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	res = (char *) malloc(end - start + 1);
	if (!res)
		return (NULL);
	res = ft_memcpy(res, s1 + start, end - start);
	res[end - start] = '\0';
	return (res);
}
