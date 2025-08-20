/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:15:48 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/20 21:49:08 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	unsigned char	*src_temp;
	unsigned char	*dest_temp;

	if (src == NULL && dest == NULL)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	src_temp = (unsigned char *)src;
	dest_temp = (unsigned char *)dest;
	while (n > 0)
	{
		dest_temp[n - 1] = src_temp[n - 1];
		n--;
	}
	return (dest_temp);
}
/*
int	main(void)
{
	char	array[] = "1";
	char	*dest;

	dest = ft_memmove(array + 1, array, 1);
	printf("%s", dest);
}*/
