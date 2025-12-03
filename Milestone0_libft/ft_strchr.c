/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:44:07 by anying            #+#    #+#             */
/*   Updated: 2025/11/14 11:44:07 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == uc)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (uc == 0)
		return ((char *)(s + i));
	return (NULL);
}
