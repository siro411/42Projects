/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:27:00 by anying            #+#    #+#             */
/*   Updated: 2025/12/18 17:27:02 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *stash)
{
	size_t	i;
	t_list	*tmp;

	if (!stash)
		return (0);
	tmp = ft_lst_get_last(stash);
	i = 0;
	while (tmp->content[i])
	{
		if (tmp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	generate_line(char **line, t_list *stash)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				*line = malloc(sizeof(char) * (len + 1));
				return ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

t_list	*ft_lst_get_last(t_list *stash)
{
	if (!stash)
		return (NULL);
	while (stash->next)
		stash = stash->next;
	return (stash);
}

t_list	*get_clean_node(t_list *last, size_t i)
{
	t_list	*new_node;
	size_t	j;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	j = 0;
	while (last->content[i + 1 + j])
		j++;
	new_node->content = malloc(sizeof(char) * (j + 1));
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	i++;
	j = 0;
	while (last->content[i])
		new_node->content[j++] = last->content[i++];
	new_node->content[j] = '\0';
	new_node->next = NULL;
	return (new_node);
}

void	free_stash(t_list **stash)
{
	t_list	*next_node;
	t_list	*current;

	if (!stash || !*stash)
		return ;
	current = *stash;
	next_node = NULL;
	while (current)
	{
		next_node = current->next;
		free(current->content);
		free(current);
		current = next_node;
	}
	*stash = NULL;
}
