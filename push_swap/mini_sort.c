/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 05:44:53 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/16 05:44:53 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	move_min_to_top(t_list **stack_a)
{
	int	min_pos;
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	min_pos = find_min_pos(*stack_a);
	if (min_pos > stack_size / 2)
	{
		while (min_pos < stack_size)
		{
			reverse_rotate_a(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			rotate_a(stack_a);
			min_pos--;
		}
	}
}

static void	sort_three_numbers(t_list **stack)
{
	int	value1;
	int	value2;
	int	value3;

	value1 = *(int *)(*stack)->content;
	value2 = *(int *)(*stack)->next->content;
	value3 = *(int *)(*stack)->next->next->content;
	if (value1 > value2 && value2 > value3 && value1 > value3)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (value1 > value2 && value2 < value3 && value1 > value3)
		rotate_a(stack);
	else if (value1 < value2 && value2 > value3 && value1 > value3)
		reverse_rotate_a(stack);
	else if (value1 > value2 && value2 < value3 && value1 < value3)
		swap_a(stack);
	else if (value1 < value2 && value2 > value3 && value1 < value3)
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

static void	sort_four_numbers(t_list **stack_a, t_list **stack_b)
{
	move_min_to_top(stack_a);
	push_to_b(stack_a, stack_b);
	sort_three_numbers(stack_a);
	push_to_a(stack_b, stack_a);
}

static void	sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
	move_min_to_top(stack_a);
	push_to_b(stack_a, stack_b);
	sort_four_numbers(stack_a, stack_b);
	push_to_a(stack_b, stack_a);
}

void	mini_sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 3)
		sort_three_numbers(stack_a);
	else if (stack_size == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five_numbers(stack_a, stack_b);
}
