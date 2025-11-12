/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:18:06 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/06 18:39:07 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	is_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (number[i] == '\0')
		return (0);
	while (number[i] != '\0')
	{
		if (!(ft_isdigit(number[i])))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_list *node)
{
	t_list	*current;
	t_list	*checker;

	current = node;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (*(int *)current->content == *(int *)checker->content)
				return (0);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}
