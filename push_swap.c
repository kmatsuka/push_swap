/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:09:14 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 04:45:12 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	char	**str;
	int		i;
	int		j;

	if (argc == 1)
		return (0);
	my_make_dummynode(&stack_a, &stack_b);
	i = 0;
	while (++i < argc)
	{
		str = my_split_singlespace(argv[i]);
		j = -1;
		while (str[++j])
		{
			my_checkif_error_duplicate(stack_a, str[j]);
			my_lstadd_front(stack_a, my_lstnew(ft_atoi(str[j])));
		}
		my_free_splitedstr(str);
	}
	if (!my_checkif_sorted(stack_a))
		my_select_algorithm(stack_a, stack_b);
	my_lstfree(stack_a, stack_b);
	return (0);
}
