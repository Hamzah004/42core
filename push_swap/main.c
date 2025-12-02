/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:19:44 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/12 02:06:30 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

void	print_stack(t_list *stack)
{
	t_list	*current;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}

static void	input_parsing(int argc, char **argv, t_list **stack_a)
{
	int		i;
	long	number;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			free_stack_and_exit(stack_a);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_stack_and_exit(stack_a);
		init_stack(stack_a, number);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	input_parsing(argc, argv, &stack_a);
	if (!(check_duplicate(stack_a)))
		free_stack_and_exit(&stack_a);
	if (!is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) <= 5)
			mini_sort(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
