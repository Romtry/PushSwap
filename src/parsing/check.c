/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:16:50 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/18 15:01:37 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	isnmbr(char *str)
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

void	norep(char **argv)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				prnt_error(1);
			j++;
			k = 0;
		}
		i++;
		j = i + 1;
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
	norep(argv);
}
