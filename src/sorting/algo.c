/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:43:03 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/31 13:27:20 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_nsorted(t_list *a, int n)
{
	int	i;

	i = 1;
	while (a->next && i <= n)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
		i++;
	}
	return (0);
}

void	indexing(t_list **a)
{
	int		i;
	t_list	*cmp;
	t_list	*save;

	i = 0;
	save = (*a);
	cmp = (*a)->next;
	while (i < lst_len(*a))
	{
		cmp = (*a)->next;
		while (cmp->next)
		{
			if ((*a)->index != -1 || (cmp->index == -1
					&& (*a)->content > cmp->content))
				(*a) = cmp;
			cmp = cmp->next;
		}
		if ((*a)->index != -1 || (cmp->index == -1
				&& (*a)->content > cmp->content))
			(*a) = cmp;
		(*a)->index = i;
		i++;
		(*a) = save;
	}
}

void	radix(t_list **a, t_list **b)
{
	int	i;
	int	i2;

	i = 0;
	while (is_sorted(*a) == 1)
	{
		i2 = lst_len(*a);
		while (i2 > 0)
		{
			if ((((*a)->index >> i) % 2) == 1)
				ra(a);
			else
				pb(a, b);
			i2--;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
