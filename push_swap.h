/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:07:21 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 04:39:14 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_dlist
{
	int				value;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

//List
int		my_lstsize(t_dlist *lst);
void	my_lstadd_front(t_dlist *lst, t_dlist *new);
t_dlist	*my_lstnew(int value);
void	my_lstfree(t_dlist *lst1, t_dlist *lst2);
void	my_make_dummynode(t_dlist **stack1, t_dlist **stack2);

//Error
void	my_checkif_error_duplicate(t_dlist *lst, const char *str);
void	my_error(void);

//Instruction
void	push(t_dlist *stack1, t_dlist *stack2, int flag);
void	rotate(t_dlist *stack, int flag);
void	reverse_rotate(t_dlist *stack, int flag);
void	swap(t_dlist *stack, int flag);

//Algorithm
int		my_checkif_sorted(t_dlist *stack);
void	my_select_algorithm(t_dlist *stack1, t_dlist *stck2);
void	my_algorithm2(t_dlist *stack);
void	my_algorithm6(t_dlist *stack1, t_dlist *stack2);
void	my_algorithm7(t_dlist *stack1, t_dlist *stack2);

//Coordinate
int		my_return_coordinate(int array[], int value, int size);
int		*my_coordinate_compression(t_dlist *stack);

//split
void	my_free_splitedstr(char	**str);
char	**my_split_singlespace(char *s);

#endif
