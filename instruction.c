/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:53:41 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 03:52:52 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist *stack, int flag)
{
	t_dlist	*p;

	p = (stack->prev)->prev;
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;
	p->prev = p->next;
	(p->next)->next = p;
	p->next = stack;
	stack->prev = p;
	if (flag)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	push(t_dlist *stack1, t_dlist *stack2, int flag)
{
	t_dlist	*p1;
	t_dlist	*p2;

	p1 = stack1->prev;
	p2 = stack2->prev;
	(p1->prev)->next = stack1;
	stack1->prev = p1->prev;
	p2->next = p1;
	stack2->prev = p1;
	p1->prev = p2;
	p1->next = stack2;
	if (flag)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	rotate(t_dlist *stack, int flag)
{
	t_dlist	*p;

	p = stack->prev;
	(p->prev)->next = stack;
	stack->prev = p->prev;
	p->prev = stack;
	(stack->next)->prev = p;
	p->next = stack->next;
	stack->next = p;
	if (flag)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate(t_dlist *stack, int flag)
{
	t_dlist	*p;

	p = stack->next;
	(p->prev)->next = p->next;
	(p->next)->prev = stack;
	p->prev = stack->prev;
	p->next = stack;
	(stack->prev)->next = p;
	stack->prev = p;
	if (flag)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}
