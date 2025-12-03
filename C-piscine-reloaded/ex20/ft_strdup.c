/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:08:36 by anying            #+#    #+#             */
/*   Updated: 2025/11/09 17:08:40 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		i;
	int		l;

	l = ft_strlen(str);
	newstr = (char *) malloc ((l + 1) * sizeof(char));
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// #include <stdio.h>
// int	main(){
// 	int	i;
// 	char *src;
// 	char *dup;

// 	i = 0;
// 	src = "Hello";
// 	dup =ft_strdup(src);
// 	while (dup[i]){
// 		printf("%c",dup[i]);
// 		i++;
// 	}
// 	free(dup);
// 	dup = 0;
// 	return (0);
// }
