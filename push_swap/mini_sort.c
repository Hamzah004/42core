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
		swap(stack);
		rev_rotate(stack);
	}
	else if (value1 > value2 && value2 < value3 && value1 > value3)
		rotate(stack);
	else if (value1 < value2 && value2 > value3 && value1 > value3)
		rev_rotate(stack);
	else if (value1 > value2 && value2 < value3 && value1 < value3)
		swap(stack);
	else if (value1 < value2 && value2 > value3 && value1 < value3)
	{
		swap(stack);
		rotate(stack);
	}
}

static void	sort_four_numbers(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(*stack_a);
	if (min_pos == 3)
		rev_rotate(stack_a);
	else if (min_pos == 2)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_a);
	}
	else if (min_pos == 1)
		rotate(stack_a);
	push(stack_a, stack_b);
	sort_three_numbers(stack_a);
	push(stack_b, stack_a);
}

static void	sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;

	min_pos = find_min_pos(*stack_a);
	if (min_pos == 1)
		rotate(stack_a);
	else if (min_pos == 2)
	{
		rotate(stack_a);
		rotate(stack_a);
	}
	else if (min_pos == 3)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_a);
	}
	else if (min_pos == 4)
		rev_rotate(stack_a);
	push(stack_a, stack_b);
	sort_four_numbers(stack_a, stack_b);
	push(stack_b, stack_a);
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
