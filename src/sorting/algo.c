/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:43:03 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/25 14:30:23 by rothiery         ###   ########.fr       */
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
	printf("h_f = %d\n", *high_f);
	if (lst_high(*a, *high_f) == 0)
	{
		write(1, "srt_high1\n", 10);
		high_move(a, 1);
	}
	else if (lst_high(*a, *high_f) == 1)
	{
		write(1, "srt_high2\n", 10);
		high_move(a, 0);
	}
	else if (lst_high(*a, *high_f) == lst_len(*a))
	{
		write(1, "srt_high3\n", 10);
		high_move(a, 2);
	}
	(*high_f)++;
}

void	a_2nsort(t_list **a)
{
	int	i;

	i = 0;
	sa(a);
	while ((*a)->next->content > (*a)->next->next->content && (*a)->next->next->content > (*a)->content)
	{
		ra(a);
		sa(a);
		i++;
	}
	while (i > 0)
	{
		i--;
		rra(a);
	}
}

// void	sort_ba(t_list **a, t_list **b)
// {

// }

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
		else if (a && a->next && a->content > a->next->content)
		{
			write(1, "a > a next\n", 11);
			a_2nsort(&a);
		}
		else if ((lst_high(a, high_f) <= 2 || lst_high(a, high_f) == lst_len(a))
			&& lst_high(a, 0) != lst_len(a)) //srch_high
			sort_high(&a, &high_f);
		else if (b && b->content > a->content)
			l_bsort(&a, &b);
		else if (a && a->next && a->content < a->next->content)
		{
			write(1, "a < a next\n", 11);
			a_2sort(&a, &b, high_f);
		}
		else
			exit(0);
	}
}
