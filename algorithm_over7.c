/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_over7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:10:59 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 10:18:13 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_get_max_ndigit(int size)
{
	int	digit;

	digit = 32;
	while (--digit >= 0)
	{
		if ((size - 1) & (1 << digit))
			break ;
	}
	return (digit);
}

void	my_algorithm7(t_dlist *stack1, t_dlist *stack2)
{
	int	*array;
	int	size;
	int	max_digit;
	int	digit;
	int	i;

	array = my_coordinate_compression(stack1);
	size = my_lstsize(stack1) - 1;
	max_digit = my_get_max_ndigit(size);
	digit = -1;
	while (++digit <= max_digit)
	{
		i = 0;
		while (i++ < size)
		{
			if (my_return_coordinate(array, (stack1->prev)->value, size)
				& (1 << digit))
				rotate(stack1, 1);
			else
				push(stack1, stack2, 0);
		}
		while (stack2 != stack2->next)
			push(stack2, stack1, 1);
	}
	free(array);
}
