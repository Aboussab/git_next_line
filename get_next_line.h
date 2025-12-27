#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 5

# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>


size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_split(char* str);
char*	ft_copier_from(char* src ,char *dest, char c);
char*	ft_switch_var(char** str);
char*	get_next_line(int fd);

#endif