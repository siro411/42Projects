/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:44:07 by anying            #+#    #+#             */
/*   Updated: 2025/11/14 11:44:07 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	uc;
	size_t			i;

	tmp_ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tmp_ptr[i] == uc)
		{
			return ((void *)&tmp_ptr[i]);
		}
		i++;
	}
	return (NULL);
}
