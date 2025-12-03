/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:40:38 by anying            #+#    #+#             */
/*   Updated: 2025/11/09 21:40:39 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(int fd)
{
	char	buf[2049];
	int		n;

	n = read(fd, buf, 2048);
	while (n > 0)
	{
		write(1, buf, n);
		n = read(fd, buf, 2048);
	}
}
