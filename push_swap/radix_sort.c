/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:41:22 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/02 17:41:22 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	find_max(t_list *node)
{
	t_list	*current;
	int		max_value;
	int		value;

	if (!node)
		return (-1);
	current = node;
	max_value = *(int *)current->content;
	while (current)
	{
		value = *(int *)current->content;
		if (max_value < value)
			max_value = value;
		current = current->next;
	}
	return (max_value);
}

static void	insert_node(t_list **sorted_list, t_list *current)
{
	t_list	*tmp;

	if (!*sorted_list
		|| *(int *)current->content < *(int *)(*sorted_list)->content)
	{
		current->next = *sorted_list;
		*sorted_list = current;
	}
	else
	{
		tmp = *sorted_list;
		while (tmp->next
			&& *(int *)tmp->next->content < *(int *)current->content)
			tmp = tmp->next;
		current->next = tmp->next;
		tmp->next = current;
	}
}

t_list	*insertion_sort(t_list **stack_a)
{
	t_list	*sorted_list;
	t_list	*current;
	t_list	*new_node;

	sorted_list = NULL;
	current = *stack_a;
	while (current)
	{
		new_node = ft_lstnew(current->content);
		insert_node(&sorted_list, new_node);
		current = current->next;
	}
	return (sorted_list);
}

void	indices_list(t_list **stack_a)
{
	t_list	*current;
	t_list	*sorted_list;
	int		i;
	t_list	*tmp;

	current = *stack_a;
	sorted_list = insertion_sort(stack_a);
	while (current)
	{
		tmp = sorted_list;
		i = 0;
		while (tmp)
		{
			if (*(int *)current->content == *(int *)tmp->content)
			{
				*(int *)current->content = i;
				break ;
			}
			i++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_value;
	int	max_n_bit;
	int	i;
	int	j;
	int	value;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	indices_list(stack_a);
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	max_value = find_max(*stack_a);
	max_n_bit = 0;
	while ((max_value >> max_n_bit) != 0)
		max_n_bit++;
	i = 0;
	while (i < max_n_bit)
	{
		j = 0;
		while (j < size)
		{
			value = *(int *)(*stack_a)->content;
			if (((value >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_to_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_to_a(stack_b, stack_a);
		i++;
	}
}
