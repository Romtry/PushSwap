/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:26:44 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/31 15:25:40 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

// correction
// void	printind(t_list *stack_a, t_list *stack_b);
// void	printus(t_list *stack_a, t_list *stack_b);

// sort_utils
int		is_sorted(t_list *a);
void	sorting(t_list **a, t_list **b);

// lst_utils
t_list	*ft_lstnew(int content);
int		lst_len(t_list *lst);
int		lst_short(t_list **stack_a);

// algo
void	radix(t_list **a, t_list **b);
void	indexing(t_list **a);

// check
void	prnt_error(int i);
int		ft_atol(char *str);
void	norep(t_list **a);
void	check(int argc, char **argv);

// push_swap_utils
char	**ft_split(char *str, char target);

// moves
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list**b);
void	pb(t_list **a, t_list**b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
