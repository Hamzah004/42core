#include <stdio.h>
void ft_swap(int *num1, int *num2)
{
	int	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int	main(void)
{
	int	a = 10, b = 20;
	printf("a: %d, b:%d\n", a, b);
	ft_swap(&a,&b);
	printf("a: %d, b:%d\n", a, b);
}
