/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:13:32 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/03 21:30:49 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	is_sorted(t_list *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	if (*(int *)stack_a->content > *(int *)stack_a->next->content)
		return (0);
	return (is_sorted(stack_a->next));
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) <= 5)
			mini_sort(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b);
	}
}
