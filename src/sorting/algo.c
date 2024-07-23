/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:43:03 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/23 12:58:28 by rothiery         ###   ########.fr       */
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

void	sort_high(t_list **a, int *high_f)
{
	if (lst_high(*a, *high_f) == 0)
		high_move(a, 1);
	else if (lst_high(*a, *high_f) == 1)
		high_move(a, 0);
	else if (lst_high(*a, *high_f) == lst_len(*a))
		high_move(a, 2);
	(*high_f)++;
}

void	a_2nsort(t_list **a)
{
	sa(a);
	while ((*a)->next->content > (*a)->next->next->content && (*a)->next->next->content > (*a)->content)
	{
		ra(a);
		sa(a);
	}
}

void	sort_ba(t_list **a, t_list **b)
{
	pa(a, b);
	while ((*a)->next->content < (*b)->content)
	{
	}
}

void	algo(t_list *a, t_list *b, int len)
{
	int	median;
	int	high_f;

	high_f = 0;
	median = l_median(a, len);
	while (is_sorted(a) != 0 || b)
	{
		if (is_sorted(a) == 0 && b && is_sortedb(b) == 0
			&& a->content > b->content)
		{
			while (b)
				pa(&a, &b);
		}
		else if (b && b->content > a->content)
		{
			write(1, "b > a\n", 6);
			pa(&a, &b);
		}
		else if (a->content > a->next->content)
		{
			write(1, "a > a next\n", 11);
			a_2nsort(&a);
		}
		// else if (lst_high(a, high_f) <= 2 || lst_high(a, high_f) == lst_len(a)) //srch_high
		// 	sort_high(&a, &high_f);
		else if (a->content < a->next->content)
		{
			write(1, "a < a next\n", 11);
			a_2sort(&a, &b, high_f);
		}
		else
			exit(0);
	}
}
//17 1 33 53 8 60 14 76 19 29 75 31 93 59 4 70 20 23 67 97 95 91 96 50 99 34 77 80 98 42 87 38 56 52 69 85 35 83 12 3 46 90 78 6 15 82 25 57 63 27 88 72 10 2 84 26 39 9 37 41 79 45 28 89 11 55 24 94 61 22 65 51 36 40 71 62 58 92 48 21 44 47 49 74 13 16 30 73 5 86 7 64 68 54 32 43 66 81 18 100
