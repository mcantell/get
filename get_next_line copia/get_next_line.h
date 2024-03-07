#ifndef GNL_H
#define GNL_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *checkpoint(char *left_line);
char *prendi(char *left_line);
char *ft_strjoint(char *left_line, char *buf);
char *ft_strachr(char *left_line, int c);
int len(char *str);
char *get_next_line(int fd);
char *legge_la_linea(int fd, char *left_line);
#endif