/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:56:25 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/31 14:25:38 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// correction
// void	printind(t_list *stack_a, t_list *stack_b)
// {
// 	int		i;
// 	t_list	*tmpa;
// 	t_list	*tmpb;

// 	i = 0;
// 	tmpa = stack_a;
// 	tmpb = stack_b;
// 	while (tmpa && i++ < 10)
// 	{
// 		printf("Index Stack A: %d\n", tmpa->index);
// 		tmpa = tmpa->next;
// 	}
// 	i = 0;
// 	printf("\n");
// 	while (tmpb && i++ < 15)
// 	{
// 		printf("Index Stack B: %d\n", tmpb->index);
// 		tmpb = tmpb->next;
// 	}
// 	printf("\n");
// }

void	printus(t_list *stack_a, t_list *stack_b)
{
	int		i;
	t_list	*tmpa;
	t_list	*tmpb;

	i = 0;
	tmpa = stack_a;
	tmpb = stack_b;
	while (tmpa && i++ < 10)
	{
		printf("Content Stack A: %d\n", tmpa->content);
		tmpa = tmpa->next;
	}
	i = 0;
	printf("\n");
	while (tmpb && i++ < 15)
	{
		printf("Content Stack B: %d\n", tmpb->content);
		tmpb = tmpb->next;
	}
	printf("\n");
}

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

static t_list	*init_list(int argc, char **argv)
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

t_list	*argv_sep(char **argv)
{
	int		i;
	t_list	*ret;
	char	**split;

	i = 0;
	split = ft_split(argv[1]);
	if (!split[0])
		prnt_error(2, 1, split);
	while (split[i])
		i++;
	check(split, 1);
	ret = init_list(i, split);
	free_split(split);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		exit(0);
	if (argv[1][0] == '\0')
		prnt_error(2, 0, NULL);
	if (argc == 2)
		stack_a = argv_sep(argv);
	else
	{
		check(argv + 1, 0);
		stack_a = init_list(argc - 1, argv + 1);
	}
	norep(&stack_a);
	if (is_sorted(stack_a) == 1)
		sorting(&stack_a, &stack_b);
	free_all(stack_a);
}

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
// 	rb(&stack_a);
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
// 	free_all(stack_a);
// 	free_all(stack_b);
// }
