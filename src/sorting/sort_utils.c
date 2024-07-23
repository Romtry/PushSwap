/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:42:53 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/18 14:37:21 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

// 	write(1, "OK\n", 3);

int	is_sortedb(t_list *b)
{
	while (b->next)
	{
		if (b->content < b->next->content)
			return (1);
		b = b->next;
	}
	return (0);
}

void	push_short(t_list **a, t_list **b)
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

void	sort(t_list *a, t_list *b, int len)
{
	if (len > 3)
	{
		push_short(&a, &b);
		len--;
		sort(a, b, len);
		pa(&a, &b);
	}
	else
	{
		if (a->content > a->next->content)
			sa(&a);
		if (lst_short(&a) == 2)
			rra(&a);
		else if (lst_short(&a) == 1)
			ra(&a);
		else if (is_sorted(a) == 1)
		{
			rra(&a);
			sa(&a);
		}
	}
}

void	sorting(t_list *a, t_list *b)
{
	int	len;

	len = lst_len(a);
	if (len == 2)
		sa(&a);
	else if (len <= 5)
		sort(a, b, len);
	else
		algo(a, b, len);
}
