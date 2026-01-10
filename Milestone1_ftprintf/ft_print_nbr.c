/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:39:36 by anying            #+#    #+#             */
/*   Updated: 2026/01/08 21:39:36 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_print_nbr(nbr / 10);
	count += ft_print_char((nbr % 10) + '0');
	return (count);
}
