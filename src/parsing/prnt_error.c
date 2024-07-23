/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:16:56 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/18 14:19:24 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
