/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:44:11 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/08 19:32:41 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_size;

	s_size = ft_strlen(s) + 1;
	dup = (char *)malloc(s_size);
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, s_size);
	return (dup);
}
