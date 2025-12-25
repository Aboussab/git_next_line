#include "get_next_line.h"

int	ft_split(char* str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i); 
		i++;
	}
	return (-1);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	p = (char *) malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != 0)
		s[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}

char*	ft_copier_from(char* src ,char *dest, char c)
{
	int	i;

	if (!src || !dest)
		return (NULL);
		i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	return dest;
}
char*	ft_switch_var(char** str)
{
	char*	tmp;
	char*	line;
	int		i;

	i = ft_split(*str);
	line = (char*)malloc(i + 2);
	if (!line)
		return (NULL);
	line = ft_copier_from(*str, line,'\n');
	line[ft_strlen(line)] = '\n';
	line[ft_strlen(line) + 1] = '\0';
	i = (ft_strlen(*str) - i);
	tmp =  (char*)malloc(i + 1);
	if (!tmp)
		return (NULL);
	i = ft_split(*str) + 1;
	tmp = ft_copier_from(*str + i , tmp,'\0');
	tmp[ft_strlen(tmp)] = '\0';
	free(*str);
	*str = ft_strdup(tmp);
	free (tmp);
	return (line);
}
char*	get_next_line(int fd)
{
	static char*	buffer;
	char*			tmp;
	ssize_t 		r;

	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = '\0';
	}
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer || !tmp)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		
		if (ft_split(buffer) < 0)
		{
			r = read(fd, tmp, BUFFER_SIZE);
			tmp[r] = '\0';
			buffer = ft_strjoin(buffer, tmp);
			if (!buffer)
				return (NULL);
		}
		else {
			free(tmp);
			return (ft_switch_var(&buffer));
		}
	}
	if (r == 0 && ft_strlen(buffer) > 0)
		return (ft_switch_var(&buffer));
	return NULL;
	
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char* line;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	return 0;
}