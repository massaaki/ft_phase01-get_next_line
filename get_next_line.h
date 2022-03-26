#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *get_next_line(int fd);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);

#endif