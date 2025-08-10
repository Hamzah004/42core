/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:59:36 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/08 23:11:38 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = (unsigned char)c;
		i++;
	}
	return (array);
}
/*
// Test function to compare your implementation with standard memset
void	test_memset(const char *test_name, size_t size, int fill_char,
		const char *initial_data)
{
	char	*test1;
	char	*test2;
	void	*result1;
	void	*result2;
	int		content_match;
	int		return_match;

	printf("\n=== %s ===\n", test_name);
	printf("Size: %zu, Fill char: %d ('%c'), Initial: \"%s\"\n",
			size, fill_char, (fill_char >= 32
				&& fill_char <= 126) ? fill_char : '?',
			initial_data ? initial_data : "random");
	// Allocate test buffers
	test1 = malloc(size + 1);
	test2 = malloc(size + 1);
	// Initialize with test data
	if (initial_data) {
		strncpy(test1, initial_data, size);
		strncpy(test2, initial_data, size);
	} else {
		// Fill with random-ish data
		for (size_t i = 0; i < size; i++) {
			test1[i] = test2[i] = 'A' + (i % 26);
		}
	}
	test1[size] = test2[size] = '\0';
	printf("Before:     \"%.*s\"\n", (int)size, test1);
	// Apply both functions
	result1 = ft_memset(test1, fill_char, size);
	result2 = memset(test2, fill_char, size);
	printf("ft_memset:  \"%.*s\"\n", (int)size, test1);
	printf("memset:     \"%.*s\"\n", (int)size, test2);
	// Check if results match
	content_match = (memcmp(test1, test2, size) == 0);
	return_match = (result1 == test1) && (result2 == test2);
	if (content_match && return_match) {
		printf("✅ PASS - Content and return (value correct\n"));
	} else {
		printf("❌ FAIL - ");
		if (!content_match) printf("Content differs ");
		if (!return_match) printf("Return value differs ");
		printf("\n");
	}
	free(test1);
	free(test2);
}

// Test with different data types
void	test_memset_types(void)
{
	int	arr1[5] = {1, 2, 3, 4, 5};
	int	arr2[5] = {1, 2, 3, 4, 5};

	printf("\n=== TESTING WITH DIFFERENT DATA TYPES ===\n");
	// Test with integers
	printf("Before (int array): ");
	for (int i = 0; i < 5; i++) printf("%d ", arr1[i]);
	printf("\n");
	ft_memset(arr1, 0, sizeof(arr1));
	memset(arr2, 0, sizeof(arr2));
	printf("After ft_memset(arr, 0, sizeof(arr)):\n");
	printf("ft_memset: ");
	for (int i = 0; i < 5; i++) printf("%d ", arr1[i]);
	printf("\n");
	printf("memset:    ");
	for (int i = 0; i < 5; i++) printf("%d ", arr2[i]);
	printf("\n");
	if (memcmp(arr1, arr2, sizeof(arr1)) == 0) {
		printf("✅ PASS - Integer array test\n");
	} else {
		printf("❌ FAIL - Integer array test\n");
	}
}

int	main(void)
{
	printf("TESTING ft_memset IMPLEMENTATION\n");
	printf("================================\n");

	// Basic tests
	test_memset("Fill with 'A'", 10, 'A', "Hello World!");
	test_memset("Fill with zero", 8, 0, "Test123!");
	test_memset("Fill with 255", 5, 255, "abcde");
	test_memset("Empty string", 0, 'X', "test");
	test_memset("Single byte", 1, 'Z', "test");
	test_memset("Large buffer", 100, '*', NULL);

	// Edge cases
	test_memset("Fill with negative int", 6, -1, "hello!");
	test_memset("Fill with large int", 6, 300, "hello!");
		// Tests truncation to unsigned char

	// Test with different data types
	test_memset_types();

	// Test return value specifically
	printf("\n=== RETURN VALUE TEST ===\n");
	char buffer[] = "test";
	char *result = (char *)ft_memset(buffer, 'X', 4);
	printf("Original buffer address: %p\n", (void *)buffer);
	printf("Returned address:        %p\n", (void *)result);
	printf("Addresses match: %s\n", (result == buffer) ? "✅ YES" : "❌ NO");

	return (0);
}*/
