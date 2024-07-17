/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:25:23 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/17 13:03:41 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (lst_len(*b) < 1)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (lst_len(*a) < 1)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}
