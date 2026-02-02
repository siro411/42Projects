#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	toUpper(void *data)
{
	char	*str;
	int		i;

	str = (char *)data;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

#include <string.h>

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*tmp;

	// Create nodes
	head = NULL;
	second = NULL;
	third = NULL;
	// Allocate memory
	head = (t_list *)malloc(sizeof(t_list));
	second = (t_list *)malloc(sizeof(t_list));
	third = (t_list *)malloc(sizeof(t_list));
	// Check allocation
	if (!head || !second || !third)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	// Assign data and link nodes
	head->data = strdup("Node 1");
	head->next = second;
	second->data = strdup("Node 2");
	second->next = third;
	third->data = strdup("Node 3");
	third->next = NULL;
	tmp = head;
	ft_list_foreach(tmp, toUpper);
	while (tmp)
	{
		printf("the data of is %s", (char *)tmp->data);
		tmp = tmp->next;
	}
}
