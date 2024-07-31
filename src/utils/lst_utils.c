/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:20:02 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/30 13:02:46 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*tab;

	tab = NULL;
	tab = malloc(sizeof(t_list));
	if (tab)
	{
		tab->content = content;
		tab->index = -1;
		tab->next = NULL;
	}
	return (tab);
}

int	lst_len(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	lst_last(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst->content);
}

int	lst_short(t_list **stack_a)
{
	t_list	*cmp;
	t_list	*cmp2;
	int		i;

	cmp = *stack_a;
	cmp2 = *stack_a;
	i = 0;
	while (cmp)
	{
		while (cmp->content <= cmp2->content)
		{
			if (!cmp2->next)
				return (i);
			cmp2 = cmp2->next;
		}
		cmp = cmp->next;
		cmp2 = cmp;
		i++;
	}
	return (0);
}

// first pos = 1

int	lst_high(t_list *a, int h_f)
{
	t_list	*cmp;
	t_list	*cmp2;
	int		i;
	int		i2;

	i2 = 1;
	cmp = a;
	cmp2 = a;
	i = 1;
	while (i != (lst_len(a) - h_f) && cmp->next)
	{
		i = 1;
		while (cmp2)
		{
			if (cmp->content > cmp2->content)
				i++;
			cmp2 = cmp2->next;
		}
		i2++;
		cmp = cmp->next;
		cmp2 = a;
	}
	return (i2);
}
