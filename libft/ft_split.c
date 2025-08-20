/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:15:49 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/20 17:17:34 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
		while (s[i] != c)
		{
			i++;
		}
			count++;
		}
		i++;
	}
	return (count);
}
char	**ft_split(char const *s, char c)
{
	char	**result = malloc(sizeof(char *) * count_word(s, c) + 1);
}

int	main()
{
	char const *s = "this is hamzah from 42";
	printf("%zu", count_word(s,' '));
}
