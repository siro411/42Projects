/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:26:29 by anying            #+#    #+#             */
/*   Updated: 2025/11/15 11:26:29 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_size(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		n = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	num;

	num = (long)n;
	len = count_size(num);
	res = (char *)malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		res[0] = '-';
	}
	if (num == 0)
		res[0] = '0';
	res[len] = '\0';
	while (num != 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
