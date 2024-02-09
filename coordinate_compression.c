/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:38:14 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 03:51:39 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	my_bubblesort(int array[], int size)
{
	int	tmp;
	int	i;
	int	j;

	j = 0;
	while (j++ < size - 1)
	{
		i = -1;
		while (++i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
		}
	}
}

static int	*my_listtoarray(t_dlist *stack, int size)
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		exit(1);
	stack = stack->next;
	while (i < size)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
	return (array);
}

int	my_return_coordinate(int array[], int value, int size)
{
	int	i;

	i = 0;
	while (i < size && value != array[i])
		i++;
	return (i);
}

int	*my_coordinate_compression(t_dlist *stack)
{
	int	size;
	int	*array;

	size = my_lstsize(stack) - 1;
	array = my_listtoarray(stack, size);
	my_bubblesort(array, size);
	return (array);
}
