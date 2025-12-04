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
/*
// Test function to compare your implementation with expected behavior
void	test_strlcpy(const char *test_name, char *dest1, char *dest2,
					const char *src, size_t size, size_t dest_size)
{
	size_t	result1;
	size_t	result2;

	printf("\n=== %s ===\n", test_name);
	printf("Source: \"%s\" (len=%zu)\n", src, strlen(src));
	printf("Size parameter: %zu\n", size);
	// Reset destinations
	memset(dest1, 'X', dest_size);
	dest1[dest_size-1] = '\0';
	memset(dest2, 'X', dest_size);
	dest2[dest_size-1] = '\0';
	printf("Before: dest=\"%s\"\n", dest1);
	result1 = ft_strlcpy(dest1, src, size);
	result2 = strlcpy(dest2, src, size);
	printf("ft_strlcpy result: %zu, dest=\"%s\"\n", result1, dest1);
	printf("   strlcpy result: %zu, dest=\"%s\"\n", result2, dest2);
	if (result1 == result2 && strcmp(dest1, dest2) == 0) {
		printf("✅ PASS\n");
	} else {
		printf("❌ FAIL\n");
	}
}
int	main(void)
{
	char dest1[20], dest2[20];

	// Test cases
	test_strlcpy("Normal copy", dest1, dest2, "hello", 20, 20);
	test_strlcpy("Size 0", dest1, dest2, "hello", 0, 20);
	test_strlcpy("Size 1", dest1, dest2, "hello", 1, 20);
	test_strlcpy("Truncation", dest1, dest2, "hello world", 6, 20);
	test_strlcpy("Empty source", dest1, dest2, "", 10, 20);
	test_strlcpy("Exact fit", dest1, dest2, "test", 5, 20);

	// Your original test case issue:
	printf("\n=== YOUR ORIGINAL TEST ISSUE ===\n");
	char src[] = "is";
	char dest_yours[15];
	char dest_real[15];

	strcpy(dest_yours, "this");
	strcpy(dest_real, "this");

	printf("Your test: ft_strlcpy result = %zu\n", ft_strlcpy(dest_yours, src,
			sizeof(dest_yours)));
	printf("But you called strlcpy with size=0: %zu\n", strlcpy(dest_real, src,
			0));
	printf("This is comparing different parameters!\n");

	// Correct comparison:
	strcpy(dest_yours, "this");
	strcpy(dest_real, "this");
	size_t your_result = ft_strlcpy(dest_yours, src, sizeof(dest_yours));
	size_t real_result = strlcpy(dest_real, src, sizeof(dest_real));

	printf("\nCORRECT comparison:\n");
	printf("ft_strlcpy(dest, src, %zu) = %zu, dest=\"%s\"\n",
			sizeof(dest_yours), your_result, dest_yours);
	printf("   strlcpy(dest, src, %zu) = %zu, dest=\"%s\"\n",
			sizeof(dest_real), real_result, dest_real);

	return (0);
}*/
