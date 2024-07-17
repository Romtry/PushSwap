/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:16:50 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/04 11:24:52 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

// int	main(void)
// {
// 	char	*test[sizeof(char *) * 3];

// 	test[0] = "test";
// 	test[1] = "   encore    ";
// 	check(0, test);
// }
