/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:27:41 by anying            #+#    #+#             */
/*   Updated: 2025/12/18 17:27:42 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				read_and_stash(int fd, t_list **stash);
void				extract_line(t_list *stash, char **line);
void				clean_stash(t_list **stash);
void				add_to_stash(t_list **stash, char *buf);

int					found_newline(t_list *stash);
void				generate_line(char **line, t_list *stash);
t_list				*ft_lst_get_last(t_list *stash);
t_list				*get_clean_node(t_list *last, size_t i);
void				free_stash(t_list **stash);

#endif
