#include "tokenize.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/**
 *main - simple shell
 *@argc: argument count
 *@argv: argument vector
 *@envp: array of environment variables
 *
 *Return: Always 0
 */
int main(__attribute__((unused))int argc, char *argv[], char *envp[])
{
	char *lineptr = NULL;
	size_t length = 0;
	ssize_t nread;
	int status;
	pid_t pid;
	int i = 0;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		nread = getline(&lineptr, &length, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		}
		lineptr[nread - 1] = '\0';
		argv = word_array(lineptr, " ");
		while (argv[i] != NULL)
			++i;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
	free(lineptr);
	return (0);
}
