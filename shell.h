#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;
void exit_shell(char **cmd, char *line);

void free_buf(char **buf);
int _strcmp(const char *s1, const char *s2);

#endif
