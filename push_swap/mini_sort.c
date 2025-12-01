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

// static void	sort_four_numbers(t_list **stack_a, t_list **stack_b) // 1, 2,
	// {
	// }
	//
	// static void	sort_five_numbers(t_list **stack_a, t_list **stack_b) // 1,
	// {
	// }

	void
	mini_sort(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 3)
		sort_three_numbers(stack_a);
}
