/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:44:09 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/31 13:58:10 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char	**arr_m(char **arr, char *wrd, int cnt)
{
	if (wrd[0] != '\0')
	{
		if (arr == NULL)
		{
			arr = malloc(sizeof(char *) * (cnt + 2));
			arr[cnt + 1] = NULL;
		}
		arr[cnt] = wrd;
	}
	else
	{
		if (arr == NULL)
		{
			arr = malloc(sizeof(char *) * (cnt + 1));
			arr[cnt] = NULL;
		}
		free(wrd);
	}
	return (arr);
}

char	**ft_split(char *str, char c)
{
	static char	**arr = NULL;
	char		*wrd;
	int			i;
	int			j;
	static int	cnt = 0;

	wrd = NULL;
	j = -1;
	i = 0;
	cnt++;
	while (str[i] == c)
		i++;
	str = str + i;
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	wrd = malloc(sizeof(char) * (i + 1));
	while (++j < i)
		wrd[j] = str[j];
	wrd[j] = '\0';
	if (str[i])
		ft_split(str + i, c);
	arr = arr_m(arr, wrd, cnt - 1);
	return (cnt--, arr);
}
