#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		tmp;
	t_list	*head;

	head = lst;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}

void	*new_node(int num)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = (void *)(long)num;
	new_node->next = NULL;
	return (new_node);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%d] -> ", (int)(long)lst->data);
		lst = lst->next;
	}
	printf("NULL\n");
}
int	cmp(int a, int b)
{
	return (a <= b);
}

int	main(void)
{
	t_list	*head;

	head = new_node(7);
	head->next = new_node(5);
	head->next->next = new_node(1);
	head->next->next->next = new_node(8);
	print_list(head);
	sort_list(head, cmp);
	print_list(head);
	return (0);
}
