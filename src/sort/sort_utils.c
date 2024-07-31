/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:42:53 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/31 14:24:39 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	push_short(t_list **a, t_list **b)
{
	int	i;

	i = lst_short(a);
	while (i > 0 && i <= 2)
	{
		ra(a);
		i--;
	}
	while (i > 2 && i <= 4)
	{
		rra(a);
		i++;
	}
	pb(a, b);
}

static void	sort(t_list **a, t_list **b, int len)
{
	if (len > 3)
	{
		push_short(a, b);
		len--;
		sort(a, b, len);
		pa(a, b);
	}
	else
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		if (lst_short(a) == 2)
			rra(a);
		else if (lst_short(a) == 1)
			ra(a);
		else if (is_sorted(*a) == 1)
		{
			rra(a);
			sa(a);
		}
	}
}

void	sorting(t_list **a, t_list **b)
{
	int	len;

	len = lst_len(*a);
	if (len == 2)
		sa(a);
	else if (len <= 5)
		sort(a, b, len);
	else
	{
		indexing(a);
		radix(a, b);
	}
}
