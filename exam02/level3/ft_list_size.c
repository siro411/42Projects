#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

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
	head->data = "Node 1";
	head->next = second;
	second->data = "Node 2";
	second->next = third;
	third->data = "Node 3";
	third->next = NULL;
	printf("size is %d", ft_list_size(head));
}
