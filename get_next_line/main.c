#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*buffer;

	fd = open("test", O_RDWR, 0644);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("%s", buffer);
		free(buffer);
	}
	close(fd);
}
