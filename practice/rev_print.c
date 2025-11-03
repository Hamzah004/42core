#include <unistd.h>
int	len(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}
int	main(int ac, char **av)
{
	int	i;
	if (ac == 2)
	{
 		i = len(av[1]) - 1;
		while (av[1][i])
		{
			write(1,&av[1][i],1);
			i--;
		}
	write(1,"\n",1);
	}
}
