#include "get_next_line.h"

char*	ft_switch_var(char** str)
{
	char*	tmp;
	char*	line;
	int		i;

	i = ft_split(*str);
	if (i >= 0)
	{
		line = (char*)malloc(i + 2);
		if (!line)
			return (NULL);
		line = ft_copier_from(*str, line,'\n');
		i = (ft_strlen(*str) - i);
		tmp =  (char*)malloc(i + 1);
		if (!tmp)
			return (NULL);
		i = ft_split(*str) + 1;
		tmp = ft_copier_from(*str + i, tmp,'\0');
		free(*str);
		*str = ft_strdup(tmp);
		free (tmp);
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (line);
}
char*	get_next_line(int fd)
{
	static char*	buffer;
	char*			tmp;
	char*			tmp2;
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
			tmp2 = ft_strjoin(buffer, tmp);
			free(buffer);
			buffer = ft_strdup(tmp2);
			free(tmp2);
			if (!buffer)
				return (free(tmp), NULL);
		}
		else
			return (free(tmp), ft_switch_var(&buffer));
	}
	if (r == 0 && ft_strlen(buffer) > 0)
		return (free(tmp), buffer = NULL, ft_switch_var(&buffer));
	
	return (free(tmp), NULL);
}

	/* Example: copy first line (before '\n') to `line` and remainder to `dest` */
	int main()
{
	int fd = open("file.txt", O_RDONLY);
	char* line;
	while((line = get_next_line(fd))!= NULL)
    {
        printf("%s", line);
	    free(line);
    }

	return 0;
}
