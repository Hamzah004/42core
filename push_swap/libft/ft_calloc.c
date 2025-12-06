/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:52:20 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/25 17:10:27 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;

	if (size == 0 || nmemb == 0)
		return (malloc(1));
	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}
