#include "libft.h"

int	ft_isascii(int	c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	printf("Me: %d\n",ft_isascii('1'));
	printf("Original: %d\n",isascii('a'));
}*/
