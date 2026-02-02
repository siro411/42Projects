#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void	ft_list_remove_if(t_list **begin_list, void *data_ref,
// 		int (*cmp)(void *, void *))
// {
// 	t_list	*curr;
// 	t_list	*prev;
// 	t_list	*tmp;

// 	if (!begin_list || !*begin_list)
// 		return ;
// 	curr = *begin_list;
// 	prev = NULL;
// 	while (curr)
// 	{
// 		if (!cmp(curr->data, data_ref))
// 		{
// 			if (prev == NULL)
// 			{
// 				*begin_list = curr->next;
// 			}
// 			else
// 			{
// 				prev->next = curr->next;
// 			}
// 			tmp = curr;
// 			curr = curr->next;
// 			free(tmp);
// 		}
// 		else
// 		{
// 			prev = curr;
// 			curr = curr->next;
// 		}
// 	}
// }

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list	*tmp;

	if (!begin_list || !*begin_list)
	{
		return ;
	}
	if (!cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
	}
}

void	push(t_list **head, void *data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("[%s] -> ", (char *)list->data);
		list = list->next;
	}
	printf("NULL\n");
}
int	cmp(void *data1, void *data2)
{
	return (strcmp((char *)data1, (char *)data2));
}

int	main(void)
{
	t_list	*head;

	head = NULL;
	// 构造链表: "42" -> "Hello" -> "42" -> "World" -> "42" -> NULL
	push(&head, "42"); // 尾部
	push(&head, "World");
	push(&head, "42"); // 中间
	push(&head, "Hello");
	push(&head, "42");
	print_list(head);
	ft_list_remove_if(&head, "42", cmp);
	print_list(head);
	return (0);
}
