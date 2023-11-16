#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define DELIM " \t\r\n\a\""
extern char **environ;

int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s1);
int test_path(char **args);
int _putchar(char c);
char *_strdup(char *s1);
int readline(int fd, char *buf, int nbytes);
int make_args(char *cmd, char **args);
int execution(char **args);
int print_nums(int n);
int check_file(char *path);
int cmd_not_found(char *args[], int counter);
int test_builtin(char **args, int cmdstat);
char *_getenv(char *env);
char *append_cmd(char *path, char *cmd);
void free_buf(char *line);
void free_double(char **doublea, int heigth);

#endif
