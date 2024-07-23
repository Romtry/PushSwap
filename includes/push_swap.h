/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:26:44 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/19 11:06:14 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	a_2sort(t_list **a, t_list **b, int high_f);
void	high_move(t_list **a, int n);
int		lst_n(t_list *b, int n);
int		is_sorted(t_list *a);
int		is_sortedb(t_list *b);
int		l_median(t_list *a, int len);
int		lst_high(t_list *a, int h_f);
void	algo(t_list *a, t_list *b, int len);
void	printus(t_list *stack_a, t_list *stack_b);
int		lst_len(t_list *lst);
int		lst_last(t_list *lst);
int		lst_short(t_list **stack_a);
void	sorting(t_list *a, t_list *b);
int		is_sorted(t_list *a);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list**b);
void	pb(t_list **a, t_list**b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
t_list	*ft_lstnew(int content);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atol(char *str);
int		ft_strlen(char *str);
void	norep(char **argv);
void	isnmbr(char *str);
char	**ft_split(char *str, char target);
void	prnt_error(int i);
int		cnt_wrd(char **str);
void	check(int argc, char **argv);

#endif
