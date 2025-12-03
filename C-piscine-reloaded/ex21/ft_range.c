/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:37:35 by anying            #+#    #+#             */
/*   Updated: 2025/11/09 17:37:37 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*nums;
	int	i;

	if (min >= max)
	{
		return (0);
	}
	nums = malloc(sizeof(int) * (max - min));
	if (nums == 0)
	{
		return (0);
	}
	i = 0;
	while (i < (max - min))
	{
		nums[i] = min + i;
		i++;
	}
	return (nums);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i;
// 	int	min;
// 	int	max;
// 	int	*tab;

// 	tab = 0;
// 	min = 4;
// 	max = 9;
// 	tab = ft_range(min, max);
// 	i = 0;
// 	while (i < (max - min))
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	tab = 0;
// 	return (0);
// }
