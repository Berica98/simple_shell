#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

void execute(char *format);
void shell_print(const char *format);
void read_command(char *format, size_t n);

#endif
