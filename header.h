#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

char *get(void);
void *_realloc(void *pointer, unsigned int old, unsigned int new);
char **token(char *format, char *delim);
int exec(char **args);
void shell_print(const char *format);

#endif
