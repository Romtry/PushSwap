/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:27:07 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/18 16:05:58 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_list **a)
{
	t_list	*swap;
	int		temp;

	swap = (*a)->next;
	temp = swap->content;
	swap->content = (*a)->content;
	(*a)->content = temp;
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	t_list	*swap;
	int		temp;

	swap = (*b)->next;
	temp = swap->content;
	swap->content = (*b)->content;
	(*b)->content = temp;
	write(1, "sb\n", 3);
}

static void	sa_(t_list **a)
{
	t_list	*swap;
	int		temp;

	swap = (*a)->next;
	temp = swap->content;
	swap->content = (*a)->content;
	(*a)->content = temp;
}

static void	sb_(t_list **b)
{
	t_list	*swap;
	int		temp;

	swap = (*b)->next;
	temp = swap->content;
	swap->content = (*b)->content;
	(*b)->content = temp;
}

void	ss(t_list **a, t_list **b)
{
	sa_(a);
	sb_(b);
	write(1, "ss\n", 3);
}
