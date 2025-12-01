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
int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		i;
	long	number;

	t_list	*stack_b;
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
	printf("stack before sort:\n");
	print_stack(stack_a);
	// swap(&stack_a);
	// printf("stack a after:\n");
	// print_stack(stack_a);
	// printf("size of linked list: %d\n", ft_lstsize(stack_a));
	// if (!is_sorted(stack_a))
	// 	printf("not sorted\n");

	// printf("pos of min value in the stack: %d\n", find_min_pos(stack_a));
	if (!is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) <= 5)
			mini_sort(&stack_a,&stack_b);
	}
	printf("stack after sort:\n");
	print_stack(stack_a);
	// if (is_sorted(stack_a))
	// 	printf("sorted\n");
	// printf("stack top: %d\n", stack_a->content);
	// rev_rotate(&stack_a);
	// printf("stack a after:\n");
	// print_stack(stack_a);
	ft_lstclear(&stack_a, free);
	return (0);
}
