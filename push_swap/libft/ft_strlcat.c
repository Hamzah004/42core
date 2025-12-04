/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:13:23 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/09 20:05:30 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_length;
	size_t	src_length;

	i = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (size <= dest_length)
		return (size + src_length);
	while (src[i] != '\0' && (dest_length + i) < (size - 1))
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest_length + src_length);
}
/*
int	main(void)
{
	char	src[] = "is";
	char	dest[] = "hello";

	printf("Me: %zu\n", ft_strlcat(dest, src, sizeof(dest)));
	printf("Original: %zu\n", strlcat(dest, src, sizeof(dest)));
	printf("dest: %s", dest);
}*/
