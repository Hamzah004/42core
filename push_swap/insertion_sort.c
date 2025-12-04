/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 04:47:16 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/04 04:47:16 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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

static t_list	*insertion_sort(t_list **stack_a)
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
