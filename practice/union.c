#include <unistd.h>

int main(int ac, char **av)
{
  if (ac == 3)
	{
    int i = 0;
    int ascii[256] = {0};
    while (av[1][i])
		{
      if (ascii[(int)av[1][i]] == 0)
			{
        write(1, &av[1][i], 1);
        ascii[(int)av[1][i]] = 1;
      }
      i++;
    }
    i = 0;
    while (av[2][i])
		{
      if (ascii[(int)av[2][i]] == 0)
			{
        write(1, &av[2][i], 1);
        ascii[(int)av[2][i]] = 1;
      }
      i++;
    }
  }
  write(1, "\n", 1);
  return (0);
}
