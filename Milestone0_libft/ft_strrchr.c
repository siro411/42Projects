/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:44:07 by anying            #+#    #+#             */
/*   Updated: 2025/11/14 11:44:07 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned int	i;
	char			cc;

	res = NULL;
	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
		{
			res = (char *)(s + i);
		}
		i++;
	}
	if (s[i] == (char) c)
	{
		res = (char *)(s + i);
	}
	return (res);
}
