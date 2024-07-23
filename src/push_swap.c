/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:56:25 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/19 11:25:11 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_list *a)
{
	t_list	*temp;

	while (a->next)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	free(a);
}

void	printus(t_list *stack_a, t_list *stack_b)
{
	int i;
	t_list	*tmpa;
	t_list	*tmpb;

	i = 0;
	tmpa = stack_a;
	tmpb = stack_b;
	while (tmpa && i++ < 5)
	{
		printf("Content Stack A: %d\n", tmpa->content);
		tmpa = tmpa->next;
	}
	printf("\n");
	while (tmpb && i++ < 5)
	{
		printf("Content Stack B: %d\n", tmpb->content);
		tmpb = tmpb->next;
	}
	printf("\n");
}

t_list	*init_list(int argc, char **argv)
{
	t_list	*head;
	t_list	*current;
	int		i;

	i = 0;
	head = ft_lstnew(ft_atol(argv[i]));
	i++;
	current = head;
	while (i < argc)
	{
		current->next = ft_lstnew(ft_atol(argv[i]));
		current = current->next;
		i++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 0;
	stack_b = NULL;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i])
			i++;
		check(i, split);
		stack_a = init_list(i, split);
	}
	else
	{
		check(argc - 1, argv + 1);
		stack_a = init_list(argc - 1, argv + 1);
	}
	if (is_sorted(stack_a) == 1)
		sorting(stack_a, stack_b);
	free_all(stack_a);
}

//check parser

// int	main(int argc, char **argv)
// {
// 	t_list	**a;

// 	if (argc == 2)
// 		check(argc , (char **)ft_split(argv[1], ' '));
// 	check(argc - 1, argv + 1);
// 	write(1, "ok", 2);
// 	return (0);
// }

//moves test

// int	main(int argc, char **argv)
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;

// 	stack_b = NULL;
// 	if (argc == 2)
// 	{
// 		check(argc , (char **)ft_split(argv[1], ' '));
// 		stack_a = init_list(argc , (char **)ft_split(argv[1], ' '));
// 	}
// 	else
// 	{
// 		check(argc - 1, argv + 1);
// 		stack_a = init_list(argc - 1, argv + 1);
// 	}
// 	printus(stack_a, stack_b);
// 	sa(&stack_a);
// 	printus(stack_a, stack_b);
// 	pb(&stack_a, &stack_b);
// 	printus(stack_a, stack_b);
// 	pb(&stack_a, &stack_b);
// 	printus(stack_a, stack_b);
// 	sb(&stack_b);
// 	printus(stack_a, stack_b);
// 	ss(&stack_a, &stack_b);
// 	printus(stack_a, stack_b);
// 	ra(&stack_a);
// 	printus(stack_a, stack_b);
// 	rb(&stack_b);
// 	printus(stack_a, stack_b);
// 	rr(&stack_a, &stack_b);
// 	printus(stack_a, stack_b);
// 	rra(&stack_a);
// 	printus(stack_a, stack_b);
// 	rrb(&stack_b);
// 	printus(stack_a, stack_b);
// 	rrr(&stack_a, &stack_b);
// 	printus(stack_a, stack_b);
// 	pa(&stack_a, &stack_b);
// 	printus(stack_a, stack_b);
// 	exit(0);
// }
