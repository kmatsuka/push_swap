/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:05:31 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 04:41:27 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_lstsize(t_dlist *lst)
{
	int		size;
	t_dlist	*p;

	size = 0;
	p = lst;
	while (lst)
	{
		size++;
		if (lst->next == p)
			return (size);
		lst = lst->next;
	}
	return (-1);
}

void	my_lstadd_front(t_dlist *lst, t_dlist *new)
{
	if (lst && new)
	{
		new->next = lst->next;
		new->prev = lst;
		(lst->next)->prev = new;
		lst->next = new;
	}
}

t_dlist	*my_lstnew(int value)
{
	t_dlist	*new_node;

	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_node)
		exit (1);
	new_node->value = value;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

void	my_lstfree(t_dlist *lst1, t_dlist *lst2)
{
	t_dlist	*p;
	t_dlist	*now;
	t_dlist	*forward;

	if (lst1->next == lst1)
		free(lst1);
	else
	{
		p = lst1;
		now = lst1;
		forward = lst1->next;
		while (forward != p)
		{
			free(now);
			now = forward;
			forward = forward->next;
		}
		free(now);
	}
	free(lst2);
}

void	my_make_dummynode(t_dlist **stack1, t_dlist **stack2)
{
	*stack1 = my_lstnew(0);
	*stack2 = my_lstnew(0);
}
