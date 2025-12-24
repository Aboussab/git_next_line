#include "get_next_line.h"

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
char*	ft_copier_from(char** src ,char **dest, char c)
{
	int	i;

	if (!src || !dest)
		return (NULL);
		i = 0;
	while (src[i] || *src[i] == c)
	{
		*dest[i] = *src[i];
		i++;
	}
	return *dest;
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

char*	ft_switch_var(char** str)
{
	char*	tmp;
	char*	line;
	int		i;

	i = ft_split(*str);
	if (i >= 0)
	{
		if (i != 0 )
		{
			line = (char*)malloc(i + 1);
			if (!line)
				return (NULL);
			line = ft_copier_from(str, &line,'\n');
			i = (ft_strlen(*str) - i);
			tmp =  (char*)malloc(i + 1);
			if (!tmp)
				return (NULL);
			i = ft_split(*str) + 1;
			tmp = ft_copier_from(**(str + i), &tmp,'\0');
			free(*str);
			*str = ft_strdup(tmp);
		}	
	}
	return (line);
}

char*	get_next_line(int fd)
{
	static char*	buffer;
	char*			tmp;
	ssize_t readed;
	char *joined;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer || !tmp)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	while (1)
	{
		if (ft_split(buffer) < 0)
		{
			readed = read(fd, tmp, BUFFER_SIZE);
			if (readed <= 0)
				break;
				joined = ft_strjoin(buffer, tmp);
				free (buffer);
				buffer = joined;
				free(tmp);
		}
		else if (ft_split(buffer) > 0)
		{
			return (ft_switch_var(&buffer));
		}
		else
			break;
	}
	return NULL;
}

int main()
{
	int fd;
	char *line;
	int i = 3;

	fd = open("file.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
}