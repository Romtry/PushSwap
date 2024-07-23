/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:26:53 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/18 14:41:10 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_list **a)
{
	int		i2;
	int		i;
	t_list	*l1;

	l1 = *a;
	while (l1->next)
		l1 = (l1)->next;
	i = (l1)->content;
	l1 = *a;
	while ((l1))
	{
		i2 = (l1)->content;
		(l1)->content = i;
		l1 = (l1)->next;
		i = i2;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	int		i2;
	int		i;
	t_list	*l1;

	l1 = *b;
	while (l1->next)
		l1 = (l1)->next;
	i = (l1)->content;
	l1 = *b;
	while ((l1))
	{
		i2 = (l1)->content;
		(l1)->content = i;
		l1 = (l1)->next;
		i = i2;
	}
	write(1, "rrb\n", 4);
}

static void	rra_(t_list **a)
{
	int		i2;
	int		i;
	t_list	*l1;

	l1 = *a;
	while (l1->next)
		l1 = (l1)->next;
	i = (l1)->content;
	l1 = *a;
	while ((l1))
	{
		i2 = (l1)->content;
		(l1)->content = i;
		l1 = (l1)->next;
		i = i2;
	}
}

static void	rrb_(t_list **b)
{
	int		i2;
	int		i;
	t_list	*l1;

	l1 = *b;
	while (l1->next)
		l1 = (l1)->next;
	i = (l1)->content;
	l1 = *b;
	while ((l1))
	{
		i2 = (l1)->content;
		(l1)->content = i;
		l1 = (l1)->next;
		i = i2;
	}
}

void	rrr(t_list **a, t_list **b)
{
	rra_(a);
	rrb_(b);
	write(1, "rrr\n", 4);
}
