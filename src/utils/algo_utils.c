/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:07:57 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/25 15:45:06 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	l_bsort_move2(t_list **a, t_list **b, int cmp)
{
	int	i;

	i = 1;
	write(1, "lbsort_m2\n", 10);
	printus(*a, *b);
	printf("lst_len = %d lst_n = %d\n", (lst_len(*b) / 2), lst_n(*b, (lst_len(*b) / 2)));
	pb(a, b);
	while (*b && lst_last(*b) < cmp)
	{
		rrb(b);
		sb(b);
		i++;
	}
	// printus(NULL, *b);
	// printf("a = %d i = %d lst_n = %d\n", (*a)->content, (lst_len(*b) / 2) + i - 1, lst_n(*b, (lst_len(*b) / 2) + i - 2));
	if ((*a)->content < lst_n(*b, (lst_len(*b) / 2) + i / 2))
		l_bsort_move2(a, b, (*a)->content);
	while (i > 0 && is_sorted(*b) == 1)
	{
		rb(b);
		i--;
	}
}

int	l_bsort_move1(t_list **a, t_list **b)
{
	int	i;

	i = 1;
	printus(*a, *b);
	printf("lst_len = %d lst_n = %d\n", (lst_len(*b) / 2), lst_n(*b, (lst_len(*b) / 2)));
	pa(a, b);
	sa(a);
	while ((*a)->next->content > (*a)->next->next->content && lst_high(*a, 0) > 2)
	{
		ra(a);
		if (((*a)->content > (*a)->next->content))
			sa(a);
	}
	while (lst_high(*a, 0) < 2)
		rra(a);
	i++;
	if (*b && (*b)->content > (*a)->content)
		l_bsort(a, b);
	while (i > 0)
	{
		write(1, "test\n", 5);
		if (lst_last(*a) < (*a)->content && *b && lst_last(*a) > (*b)->content)
			rra(a);
		pb(a, b);
		i--;
	}
	return (i);
}

void	l_bsort(t_list **a, t_list **b)
{
	int	cmp;

	write(1, "lbsort\n", 7);
	cmp = (*a)->content;
	if (cmp < (*b)->content && (!(*b)->next || cmp > (*b)->next->content))
	{
		write(1, "a < b > bnext\n", 14);
		pa(a, b);
		sa(a);
	}
	else if (cmp < lst_n(*b, (lst_len(*b) / 2)))
	{
		l_bsort_move2(a, b, cmp);
	}
	else if (*b && (*b)->content > (*a)->content)
	{
		write(1, "lbsort_m1\n", 10);
		l_bsort_move1(a, b);
	}
	// if ((*a)->content < (*a)->next->content)
	// 	l_bsort(a, b);
	// if (lst_high(*a, 0) != lst_len(*a))
	// 	rra(a);
}
//83 92 36 91 9 46 96 54 93 76 69 10 26 81 73 22 5 52 23 99 79 49 40 75 86 90 37 20 2 14 85 44 11 25 59 32 4 8 88 77 82 70 29 34 68 80 84 78 66 94 7 89 30 42 50 100 3 19 13 97 28 6 39 33 48 1 58 72 71 60 21 35 95 45 17 67 41 63 24 53 27 15 98 43 57 12 55 74 62 65 16 38 47 31 61 18 64 51 87 56 
void	a_2sort(t_list **a, t_list **b, int high_f)
{
	while ((*a)->content > lst_last(*a))
		rra(a);
	if (!(*b))
	{
		pb(a, b);
		if (high_f > 0 && lst_high(*a, 0) != lst_len(*a))
			rra(a);
	}
	// else if ((*a)->content < (*b)->content)
	// {
	// 	write(1, "lbsort\n", 7);
	// 	l_bsort(a, b);
	// }
	else if ((*a)->content > (*b)->content)
	{
		write(1, "3\n", 2);
		pb(a, b);
		if (high_f > 0 && lst_high(*a, 0) != lst_len(*a))
			rra(a);
	}
}

void	high_move(t_list **a, int n)
{
	if (n < 2)
	{
		rra(a);
		if (n == 1 && lst_high(*a, 0) != lst_len(*a))
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
