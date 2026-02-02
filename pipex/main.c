#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	id;
	pid_t	res;
	
	id = fork();
	if (id == 0)
		sleep(1);
	printf("current id: %d, parent id: %d\n", getpid(), getppid());
	 res = wait(NULL);
	if (res == -1)
		printf("nothing to wait for\n");
	else
		printf("finished execution %d\n", res);
	return (0);
}

// will wait for the child process to end and then execute the parent process
// the parent process is term before the child, a new parent is assigned to the child processes still running
