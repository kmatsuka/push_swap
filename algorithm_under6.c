/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:05:24 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 10:17:54 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	my_algorithm3(t_dlist *stack, int flag)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (stack->next)->value;
	n2 = ((stack->next)->next)->value;
	n3 = (((stack->next)->next)->next)->value;
	if (n3 < n2 && n2 < n1)
		;
	else if (n3 < n1 && n1 < n2)
	{
		reverse_rotate(stack, flag);
		swap(stack, flag);
	}
	else if (n2 < n3 && n3 < n1)
		swap(stack, flag);
	else if (n1 < n3 && n3 < n2)
		reverse_rotate(stack, flag);
	else if (n2 < n1 && n1 < n3)
		rotate(stack, flag);
	else
	{
		swap(stack, flag);
		reverse_rotate(stack, flag);
	}
}

static void	my_algorithm3_reverse(t_dlist *stack, int flag)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (stack->next)->value;
	n2 = ((stack->next)->next)->value;
	n3 = (((stack->next)->next)->next)->value;
	if (n3 < n2 && n2 < n1)
	{
		swap(stack, flag);
		reverse_rotate(stack, flag);
	}
	else if (n3 < n1 && n1 < n2)
		rotate(stack, flag);
	else if (n2 < n3 && n3 < n1)
		reverse_rotate(stack, flag);
	else if (n1 < n3 && n3 < n2)
		swap(stack, flag);
	else if (n2 < n1 && n1 < n3)
	{
		reverse_rotate(stack, flag);
		swap(stack, flag);
	}
}

static void	my_algorithm6_support(t_dlist *stack)
{
	if (my_lstsize(stack) == 3 && (stack->prev)->value < (stack->next)->value)
		swap(stack, 0);
	else if (my_lstsize(stack) == 4)
		my_algorithm3_reverse(stack, 0);
}

void	my_algorithm2(t_dlist *stack)
{
	if (((stack->prev)->value) > ((stack->next)->value))
		swap(stack, 1);
}

void	my_algorithm6(t_dlist *stack1, t_dlist *stack2)
{
	int	*array;
	int	size;
	int	ind;
	int	ind2;

	array = my_coordinate_compression(stack1);
	size = my_lstsize(stack1) - 1;
	ind = size - 3;
	ind2 = size - 3;
	while (ind2)
	{
		if (my_return_coordinate(array, (stack1->prev)->value, size) < ind)
		{
			push(stack1, stack2, 0);
			ind2--;
		}
		else
			rotate(stack1, 1);
	}
	my_algorithm3(stack1, 1);
	my_algorithm6_support(stack2);
	while (my_lstsize(stack2) > 1)
		push(stack2, stack1, 1);
	free(array);
}
