/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:22:42 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/30 18:01:20 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*a);
	(*a) = (*a)->next;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}

// void	ra(t_list **a)
// {
// 	int		i2;
// 	int		i;
// 	t_list	*l1;

// 	l1 = *a;
// 	i = (l1)->content;
// 	while (l1->next)
// 	{
// 		i2 = l1->next->content;
// 		l1->content = i2;
// 		l1 = l1->next;
// 	}
// 	l1->content = i;
// 	write(1, "ra\n", 3);
// }

void	rb(t_list **b)
{
	t_list	*s;
	t_list	*tmp;

	s = (*b)->next;
	tmp = (*b)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*b);
	(*b)->next = NULL;
	(*b) = s;
	write(1, "rb\n", 3);
}

static void	ra_(t_list **a)
{
	t_list	*s;
	t_list	*tmp;

	s = (*a)->next;
	tmp = (*a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*a);
	(*a)->next = NULL;
	(*a) = s;
}

static void	rb_(t_list **b)
{
	t_list	*s;
	t_list	*tmp;

	s = (*b)->next;
	tmp = (*b)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*b);
	(*b)->next = NULL;
	(*b) = s;
}

void	rr(t_list **a, t_list **b)
{
	ra_(a);
	rb_(b);
	write(1, "rr\n", 3);
}
