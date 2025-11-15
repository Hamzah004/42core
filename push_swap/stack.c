/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:34:16 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/01 18:40:47 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	free_stack_and_exit(t_list **stack)
{
	if (stack && *stack)
		ft_lstclear(stack, free);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	init_stack(t_list **stack_a, int number)
{
	int		*content;
	t_list	*new_node;

	content = malloc(sizeof(int));
	if (!content)
		free_stack_and_exit(stack_a);
	*content = (int)number;
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		free_stack_and_exit(stack_a);
	}
	ft_lstadd_front(stack_a, new_node);
}

// static int	find_max(t_list *node)
// {
// 	t_list	*current;
// 	t_list	*checker;
// 	int		max;
//
// 	current = node;
// 	max = *(int *)current->content;
// 	while (current)
// 	{
// 		checker = current->next;
// 		while (checker)
// 		{
// 			if (max < *(int *)checker->content)
// 				max = *(int *)checker->content;
// 			checker = checker->next;
// 		}
// 		current = current->next;
// 	}
// 	return (max);
// }

// t_list	count_sort(t_list **stack, int n, int pos)
// {
//
// 	t_list	*current;
// 	int	count[10] = {0};
//
// 	current = *stack;
// 	while (current)
// 	{
// 		++count[(*(int *)current->content/pos)%10];
// 	}
// }

// void radix_sort(t_list **stack, int ac)
// {
// 	int	max;
// 	int	pos;
//
// 	max = find_max(*stack);
// 	pos = 1;
// 	while (max/pos > 0)
// 	{
// 		count_sort(stack,ac - 1, pos);
// 		pos = pos * 10;
// 	}
// }

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	if ((*stack_a)->next == NULL)
	{
		last = *stack_a;
		*stack_a = NULL;
		ft_lstadd_front(stack_b, last);
		return ;
	}
	tmp = *stack_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, last);
}

// void	rotate_a(t_list **stack_a)
// {
// 	t_list	*start;
// 	t_list	*last;
// 	t_list *tmp;
//
// 	start = *stack_a;
// 	tmp = *stack_a;
// 	while (tmp->next->next != NULL)
// 		tmp = tmp->next;
// 	last = tmp->next;
// 	tmp->next = start;
// }
