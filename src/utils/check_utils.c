/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:58:18 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/19 10:10:58 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	l_median(t_list *a, int len)
{
	t_list	*cmp;
	t_list	*cmp2;
	int		i;

	cmp = a;
	i = 0;
	while (i != ((len / 2)))
	{
		cmp2 = a;
		i = 0;
		while (i <= ((len / 2)) && cmp2)
		{
			if (cmp->content > cmp2->content)
				i++;
			cmp2 = cmp2->next;
		}
		if (i != len / 2)
			cmp = cmp->next;
	}
	return (cmp->content);
}

int	lst_n(t_list *b, int n)
{
	t_list	*tmp;

	tmp = b;
	while (n > 0 && tmp->next)
	{
		tmp = tmp->next;
		n--;
	}
	return (tmp->content);
}

int	ft_atol(char *str)
{
	unsigned int	i;
	int				sign;
	long			ret;

	i = 0;
	sign = 1;
	ret = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (ret > INT_MAX || ret < INT_MIN)
		prnt_error(3);
	return (ret * sign);
}
