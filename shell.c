#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/**
 *main - simple shell
 *
 *Return: Always 0
 */
int main(void)
{
	char *lineptr = NULL;
	size_t length = 0;
	ssize_t nread;
	int status;
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		nread = getline(&lineptr, &length, stdin);
		if (nread == -1)
			break;
		lineptr[nread - 1] = '\0';
		pid = fork();
		if (pid == -1)
		{
			perror("Error:fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = {lineptr, NULL};

			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("Error:waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(lineptr);
	return (0);
}
