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
	ft_lstadd_back(stack_a, new_node);
}

int	find_min_pos(t_list *node)
{
	t_list	*current;
	int		min_value;
	int		node_pos;
	int		i;
	int		value;

	if (!node)
		return (-1);
	current = node;
	min_value = *(int *)current->content;
	node_pos = 0;
	i = 0;
	while (current)
	{
		value = *(int *)current->content;
		if (min_value > value)
		{
			min_value = value;
			node_pos = i;
		}
		current = current->next;
		i++;
	}
	return (node_pos);
}
