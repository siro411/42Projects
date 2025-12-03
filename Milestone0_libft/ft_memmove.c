/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:44:07 by anying            #+#    #+#             */
/*   Updated: 2025/11/14 11:44:07 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;
	size_t			count;

	tmp_src = (unsigned char *) src;
	tmp_dest = (unsigned char *) dest;
	count = 0;
	if (src == (void *)0 && dest == (void *)0)
		return (dest);
	if (tmp_src < tmp_dest)
	{
		while (len-- > 0)
			*(tmp_dest + len) = *(tmp_src + len);
	}
	else
	{
		while (count++ < len)
			*(tmp_dest++) = *(tmp_src++);
	}
	return (dest);
}
