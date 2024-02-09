/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:18:14 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 04:43:41 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_checkif_int(const char *str)
{
	int		n;
	int		sign;

	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (2);
		if (n * sign > INT_MAX / 10 || (n * sign == INT_MAX / 10
				&& *str - '0' > INT_MAX - INT_MAX / 10 * 10))
			return (1);
		if (n * sign < INT_MIN / 10 || (n * sign == INT_MIN / 10
				&& -(*str - '0') < INT_MIN - INT_MIN / 10 * 10))
			return (-1);
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (0);
}

static int	my_checkif_duplicate(t_dlist *lst, int value)
{
	t_dlist	*p;

	if (lst->prev == lst->next)
		return (0);
	p = lst;
	lst = lst->next;
	while (lst)
	{
		if (value == lst->value)
			return (1);
		if (lst->next == p)
			return (0);
		lst = lst->next;
	}
	return (0);
}

void	my_checkif_error_duplicate(t_dlist *lst, const char *str)
{
	if (my_checkif_int(str) || my_checkif_duplicate(lst, ft_atoi(str)))
		my_error();
}

void	my_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
