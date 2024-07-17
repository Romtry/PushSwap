/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:43:03 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/17 14:41:21 by rothiery         ###   ########.fr       */
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

void	l_bsort(t_list **a, t_list **b)
{
	int	i;
	int cmp;

	i = 0;
	cmp = (*a)->content;
	while (*b && (*b)->content > cmp)
	{
		pa(a, b);
		sa(a);
		i++;
	}
	while (i >= 0)
	{
		pb(a, b);
		i--;
	}
	if (lst_high(*a, 0) != lst_len(*a))
		rra(a);
}

void	a_2sort(t_list **a, t_list **b, int high_f)
{
	if (!(*b))
	{
		pb(a, b);
		if (high_f > 0 && lst_high(*a, 0) != lst_len(*a))
			rra(a);
	}
	else if ((*a)->content < (*b)->content)
	{
		l_bsort(a, b);
	}
	else if ((*a)->content > (*b)->content)
	{
		pb(a, b);
		if (high_f > 0 && lst_high(*a, 0) != lst_len(*a))
			rra(a);
	}
}

void	algo(t_list *a, t_list *b, int len)
{
	int	median;
	int	high_f;

	high_f = 0;
	median = l_median(a, len);
	if (lst_high(a, high_f) == 1)
	{
		high_f++;
		rra(&a);
		rra(&a);
	}
	while (is_sorted(a) != 0 || b)
	{
		if (is_sorted(a) == 0 && b && is_sortedb(b) == 0 && a->content > b->content)
		{
			while (b)
				pa(&a, &b);
		}
		else if (a->content > a->next->content)
			sa(&a);
		else if (lst_high(a, high_f) == 2 && lst_high(a, 0) != lst_len(a))
		{
			high_f++;
			rra(&a);
		}
		else if (a->content < a->next->content)
			a_2sort(&a, &b, high_f);
		else
			exit(0);
	}
}



