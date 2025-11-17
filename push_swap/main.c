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

	current = stack;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	long	number;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			free_stack_and_exit(&stack_a);
		number = ft_atoi(av[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_stack_and_exit(&stack_a);
		init_stack(&stack_a, number);
		i++;
	}
	if (!(check_duplicate(stack_a)))
		free_stack_and_exit(&stack_a);

	printf("stack A before: \n");
	print_stack(stack_a);
	printf("stack B before: \n");
	print_stack(stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	printf("stack A after: \n");
	print_stack(stack_a);
	printf("stack B after: \n");
	print_stack(stack_b);

	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	printf("stack A \n");
	print_stack(stack_a);
	printf("stack B \n");
	print_stack(stack_b);
	// // rotate(&stack_a);
	// printf("stack B after: \n");
	// print_stack(stack_a);
	// printf("stack B: \n");
	// print_stack(stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
