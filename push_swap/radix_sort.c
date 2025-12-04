/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:41:22 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/04 04:49:36 by hbani-at         ###   ########.fr       */
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

static int	get_number_of_max_bits(t_list *stack_a)
{
	int	number_of_max_bits;
	int	max_value;

	max_value = find_max(stack_a);
	number_of_max_bits = 0;
	while ((max_value >> number_of_max_bits) != 0)
		number_of_max_bits++;
	return (number_of_max_bits);
}

static void	process_bits(t_list **stack_a, t_list **stack_b, int size, int bit)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*(int *)(*stack_a)->content >> bit) & 1) == 1)
			rotate_a(stack_a);
		else
			push_to_b(stack_a, stack_b);
		j++;
	}
}

static void	push_all_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		push_to_a(stack_b, stack_a);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	number_of_max_bits;
	int	bit;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	indices_list(stack_a);
	size = ft_lstsize(*stack_a);
	number_of_max_bits = get_number_of_max_bits(*stack_a);
	bit = 0;
	while (bit < number_of_max_bits)
	{
		process_bits(stack_a, stack_b, size, bit);
		push_all_to_a(stack_a, stack_b);
		bit++;
	}
}
