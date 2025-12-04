/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:24:38 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/10 21:01:12 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)malloc(s1_len + s2_len + 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, s1_len + 1);
	ft_strlcpy(new_string + s1_len, s2, s2_len + 1);
	return (new_string);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("hamzah ", "bani-ata"));
}*/
