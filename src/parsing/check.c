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

static int	isnmbr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && str[1] >= '0' && str[1] <= '9')
		return (1);
	if ((str[0] == '-' && str[1] == '0') || (str[0] == '-' && str[1] == '\0'))
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	prnt_error(int i, int s, char **split)
{
	if (i == 1)
		write(1, "you can't put twice or more the same number!\n", 45);
	else if (i == 2)
		write(1, "some args aren't integer\n", 25);
	else if (i == 3)
		write(1, "number higher than intmax or lower than intmin\n", 47);
	if (s == 1)
		free_split(split);
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
				free_all(*a);
				prnt_error(1, 0, NULL);
			}
		}
		cmp = cmp->next;
	}
}

void	check(char **argv, int s)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			prnt_error(2, s, argv);
		if (ft_atol(argv[i]) == 999999999999)
			prnt_error(3, s, argv);
		if (isnmbr(argv[i]) == 1)
			prnt_error(2, s, argv);
		i++;
	}
}
