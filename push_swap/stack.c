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
#include <inttypes.h>
#include <stdio.h>
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
	ft_lstadd_back(stack_a, new_node);
}

int	find_max(t_list *node)
{
	t_list	*current;
	t_list	*checker;
	int		max;

	current = node;
	max = *(int *)current->content;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (max < *(int *)checker->content)
				max = *(int *)checker->content;
			checker = checker->next;
		}
		current = current->next;
	}
	return (max);
}

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	ft_lstadd_front(dest, tmp);
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if ((*stack)->next == NULL)
		return ;
	if (!stack || !*stack)
		return ;
	first = *stack;
	*stack = first->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}

void	rev_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if ((*stack)->next == NULL)
		return ;
	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	ft_lstadd_front(stack, last);
	tmp->next = NULL;
}

void	swap(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next == NULL)
		return ;
	if (!stack || !*stack)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	ft_lstadd_front(stack, tmp);
}

int	is_sorted(t_list *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	if (*(int *)stack_a->content > *(int *)stack_a->next->content)
		return (0);
	return (is_sorted(stack_a->next));
}
