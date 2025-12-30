/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anying <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:16:00 by anying            #+#    #+#             */
/*   Updated: 2025/12/23 17:16:02 by anying           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	ssize_t	readed;

	readed = 1;
	while (!found_newline(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
		{
			free_stash(stash);
			return ;
		}	
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == 0 || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf);
	}
}

void	add_to_stash(t_list **stash, char *buf)
{
	t_list	*new_node;
	t_list	*last;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buf);
		return ;
	}
	new_node->content = buf;
	new_node->next = NULL;
	if (!*stash)
		*stash = new_node;
	else
	{
		last = ft_lst_get_last(*stash);
		last->next = new_node;
	}
}

void	extract_line(t_list *stash, char **line)
{
	size_t	i;
	size_t	j;

	if (!stash)
		return ;
	generate_line(line, stash);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				(*line)[j] = '\0';
				return ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	size_t	i;
	t_list	*last;
	t_list	*new_node;

	i = 0;
	last = ft_lst_get_last(*stash);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\0' || last->content[i + 1] == '\0')
	{
		free_stash(stash);
		return ;
	}
	new_node = get_clean_node(last, i);
	if (!new_node)
	{
		free_stash(stash);
		return ;
	}
	free_stash(stash);
	*stash = new_node;
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (free_stash(&stash[fd]), NULL);
	read_and_stash(fd, &stash[fd]);
	if (!stash[fd])
		return (NULL);
	extract_line(stash[fd], &line);
	if (!line)
	{
		free_stash(&stash[fd]);
		return (NULL);
	}
	clean_stash(&stash[fd]);
	if (line[0] == '\0')
	{
		free_stash(&stash[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}

#include <stdio.h> // 用于 printf

int	main(void)
{
	int		fd;
	char	*line;

	// 1. 打开文件
	line = NULL;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	// 2. 循环读取
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ; // 读完了或者出错，跳出循环
		printf("%s", line); // 打印读取到的行
		free(line); // 重要：用完必须释放！
	}

	// // 3. 关闭文件
	close(fd);
	return (0);
}
