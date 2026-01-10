/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:39:36 by anying            #+#    #+#             */
/*   Updated: 2026/01/08 21:39:36 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_conversion(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (c == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count += ft_print_char('%');
	return (count);
}

static int	ft_parse_format(const char *fmt, int *i, va_list args)
{
	int	result;

	if (fmt[*i] == '%')
	{
		(*i)++;
		if (!fmt[*i])
			return (-1);
		result = ft_handle_conversion(args, fmt[*i]);
	}
	else
		result = ft_print_char(fmt[*i]);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		tmp;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		tmp = ft_parse_format(format, &i, args);
		if (tmp == -1)
		{
			va_end(args);
			return (-1);
		}
		count += tmp;
		i++;
	}
	va_end(args);
	return (count);
}
