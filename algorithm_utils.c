/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:02:01 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 03:50:40 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_checkif_sorted(t_dlist *stack)
{
	t_dlist	*p;

	p = stack;
	if (stack->next == p)
		exit(0);
	stack = stack->next;
	while (stack)
	{
		if (stack->next == p)
			return (1);
		if (stack->value < (stack->next)->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	my_select_algorithm(t_dlist *stack1, t_dlist *stack2)
{
	int	size;

	size = my_lstsize(stack1) - 1;
	if (size <= 1)
		;
	else if (size <= 2)
		my_algorithm2(stack1);
	else if (size <= 6)
		my_algorithm6(stack1, stack2);
	else
		my_algorithm7(stack1, stack2);
}
