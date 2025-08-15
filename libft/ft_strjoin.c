/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:24:38 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/15 19:53:08 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*new;
	size_t	s1_size;
	size_t	s2_size;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	new = malloc(s1_size + s2_size + 1);
	while (s1_size--)
	{
		new[s2_size] = s1[i];
		i++;
		s2_size++;
	}
	new[i] = '\0';
	return (new);
}

int	main()
{
	printf("%s",ft_strjoin("hamzah ", "bani-ata"));
}
