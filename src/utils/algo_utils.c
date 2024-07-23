/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:07:57 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/23 14:59:51 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	l_bsort_move2(t_list **a, t_list **b, int cmp)
{
	int	i;

	i = 1;
	pb(a, b);
	while (*b && lst_last(*b) < cmp)
	{
		rrb(b);
		sb(b);
		i++;
	}
	while (i > 0)
	{
		rb(b);
		i--;
	}
}

int	l_bsort_move1(t_list **a, t_list **b, int cmp)
{
	int	i;

	i = 1;
	while (*b && (*b)->content > cmp)
	{
		pa(a, b);
		sa(a);
		while ((*a)->next->content > (*a)->next->next->content)
		{
			ra(a);
			sa(a);
		}
		i++;
	}
	return (i);
}

void	l_bsort(t_list **a, t_list **b)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = (*a)->content;
	if (cmp < (*b)->content && (!(*b)->next || cmp > (*b)->next->content))
	{
		write(1, "lbsort_m2\n", 10);
		pa(a, b);
		sa(b);
	}
	else if (cmp < lst_n(*b, (lst_len(*b) / 2)))
	{
		write(1, "lbsort_m2\n", 10);
		l_bsort_move2(a, b, cmp);
	}
	else
	{
		write(1, "lbsort_m1\n", 10);
		i = l_bsort_move1(a, b, cmp);
	}
	while (i > 0)
	{
		pb(a, b);
		i--;
	}
	if (lst_high(*a, 0) != lst_len(*a))
		rra(a);
}
//83 92 36 91 9 46 96 54 93 76 69 10 26 81 73 22 5 52 23 99 79 49 40 75 86 90 37 20 2 14 85 44 11 25 59 32 4 8 88 77 82 70 29 34 68 80 84 78 66 94 7 89 30 42 50 100 3 19 13 97 28 6 39 33 48 1 58 72 71 60 21 35 95 45 17 67 41 63 24 53 27 15 98 43 57 12 55 74 62 65 16 38 47 31 61 18 64 51 87 56 
void	a_2sort(t_list **a, t_list **b, int high_f)
{
	static int	i;

	while ((*a)->content > lst_last(*a))
	{
		rra(a);
		i++;
	}
	if (!(*b))
	{
		pb(a, b);
		if (high_f > 0 && lst_high(*a, 0) != lst_len(*a))
			rra(a);
	}
	else if ((*a)->content < (*b)->content)
	{
		write(1, "lbsort\n", 7);
		l_bsort(a, b);
	}
	else if ((*a)->content > (*b)->content)
	{
		pb(a, b);
		if (high_f > 0 && lst_high(*a, 0) != lst_len(*a))
			rra(a);
	}
	i--;
	if (i >= 0)
		a_2sort(a, b, high_f);
}

void	high_move(t_list **a, int n)
{
	if (n < 2)
	{
		rra(a);
		if (n == 1)
			rra(a);
	}
	else
	{
		rra(a);
		sa(a);
		if ((*a)->next->content > (*a)->next->next->content)
		{
			ra(a);
			sa(a);
			rra(a);
		}
	}
}
