#include <unistd.h>
int	main(int ac, char **av)
{
	int	i = 0;
	if (ac == 2)
	{
		int	j;
		while (av[1][i])
		{
			if (av[1][i] >= 65 && av[1][i] <= 90)
			{
				j = 0;
				while (j < av[1][i] - 64)
				{
					write(1,&av[1][i],1);
					j++;
				}
			}
			else if (av[1][i] >= 97 && av[1][i] <= 122)
			{
				j = 0;
				while (j < av[1][i] - 96)
				{
					write(1,&av[1][i],1);
					j++;
				}
			}
			else
				write(1,&av[1][i],1);
			i++;
		}
	}
	write(1,"\n",1);
}
