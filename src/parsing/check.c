/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:16:50 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/31 14:27:27 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	isnmbr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && str[1] >= '0' && str[1] <= '9')
		prnt_error(2);
	if ((str[0] == '-' && str[1] == '0') || (str[0] == '-' && str[1] == '\0'))
		prnt_error(2);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			prnt_error(2);
		i++;
	}
}

void	prnt_error(int i)
{
	if (i == 1)
		write(1, "you can't put twice or more the same number!", 44);
	else if (i == 2)
		write(1, "some args aren't integer", 24);
	else if (i == 3)
		write(1, "number higher than intmax or lower than intmin", 46);
	exit(0);
}

void	norep(t_list **a)
{
	t_list	*cmp;
	t_list	*cmp2;

	cmp = (*a);
	cmp2 = (*a);
	while (cmp->next)
	{
		cmp2 = cmp;
		while (cmp2->next)
		{
			cmp2 = cmp2->next;
			if (cmp->content == cmp2->content)
			{
				free(*a);
				prnt_error(1);
			}
		}
		cmp = cmp->next;
	}
}

void	check(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 0)
		prnt_error(0);
	while (argv[i])
	{
		ft_atol(argv[i]);
		isnmbr(argv[i]);
		i++;
	}
}
