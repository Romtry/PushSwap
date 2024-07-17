/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:22:42 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/11 10:40:05 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_list **a)
{
	int	i2;
	int	i;
	t_list *l1;

	l1 = *a;
	i = (l1)->content;
	while (l1->next)
	{
		i2 = l1->next->content;
		l1->content = i2;
		l1 = l1->next;
	}
	l1->content = i;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	int	i2;
	int	i;
	t_list *l1;

	l1 = *b;
	i = (l1)->content;
	while (l1->next)
	{
		i2 = l1->next->content;
		l1->content = i2;
		l1 = l1->next;
	}
	l1->content = i;
	write(1, "rb\n", 3);
}

static void	ra_(t_list **a)
{
	int	i2;
	int	i;
	t_list *l1;

	l1 = *a;
	i = (l1)->content;
	while (l1->next)
	{
		i2 = l1->next->content;
		l1->content = i2;
		l1 = l1->next;
	}
	l1->content = i;
}

static void	rb_(t_list **b)
{
	int	i2;
	int	i;
	t_list *l1;

	l1 = *b;
	i = (l1)->content;
	while (l1->next)
	{
		i2 = l1->next->content;
		l1->content = i2;
		l1 = l1->next;
	}
	l1->content = i;
}

void	rr(t_list **a, t_list **b)
{
	ra_(a);
	rb_(b);
	write(1, "rr\n", 3);
}
