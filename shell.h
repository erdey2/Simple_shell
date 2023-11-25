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
#include <stdbool.h>

#define DELIM " \t\r\n\a\""
extern char **environ;

int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s1);
int _putchar(char c);
char *_strdup(char *s1);
char *_strcpy(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
char *_getline(void);
char **_strtok(char *line);
char *get_stream(void);
unsigned int check_match(char c, const char *s1);
char *mystrtok(char *s1, const char *s2);
int exec_args(char **args);
int execution(char **args);
int main(void);
void myshell(void);
void buitin_shell(void);
int _atoi(char *s);

int exit_builtin(char **args);
int cd_builtin(char **args);

#endif
