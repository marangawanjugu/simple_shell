#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define PRINT(format) printf(format)

size_t tokenizer(char *str, char *delim);
char **word_array(char *str, char *delim);

#endif
