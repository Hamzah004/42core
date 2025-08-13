/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:52:20 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/09 20:53:24 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;

	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, size);
	return (array);
}
/*
int	main(void)
{
	int	*arr;
	int	n;

	n = 5;
	arr = (int *)ft_calloc(n, sizeof(int));
	// Print the initialized values (all will be 0)
	printf("Initial values: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	// Use the array
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	printf("\nAfter assignment: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}*/
