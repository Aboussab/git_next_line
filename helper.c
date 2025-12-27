// int	ft_split(char* str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\n')
// 			return (i); 
// 		i++;
// 	}
// 	return (-1);
// }
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }
// char*	ft_copier_from(char* src ,char *dest, char c)
// {
// 	int	i;

// 	if (!src || !dest)
// 		return (NULL);
// 		i = 0;
// 	while (src[i] && src[i] != c)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return dest;
// }
// char*	ft_switch_var(char** str)
// {
// 	char*	tmp;
// 	char*	line;
// 	int		i;

// 	i = ft_split(*str);
// 	if (i >= 0)
// 	{
// 		if (i != 0 )
// 		{
// 			line = (char*)malloc(i + 1);
// 			if (!line)
// 				return (NULL);
// 			line = ft_copier_from(*str, line,'\n');
// 			i = (ft_strlen(*str) - i);
// 			tmp =  (char*)malloc(i + 1);
// 			if (!tmp)
// 				return (NULL);
// 			i = ft_split(*str) + 1;
// 			tmp = ft_copier_from(*str + i , tmp,'\0');
// 			free(*str);
// 			*str = ft_strdup(tmp);
// 		}	
// 	}
// 	return (line);
// }


// int main(void)
// {
// 	/* Example: copy first line (before '\n') to `line` and remainder to `dest` */
// 	char *str = malloc(256);
// 	if (!str)
// 		return (1);

// 	int fd = open("file.txt", O_RDONLY);
	
// 	ssize_t r = read(fd, str, 255);
	
// 	str[r] = '\0';
// 	close(fd);

// 	int index = ft_split(str);
// 	char *line = NULL;
// 	char *dest = NULL;

// 	line = malloc(index + 1);
// 		if (!line) return (1);
// 		ft_copier_from(str, line, '\n');

// 		size_t rest_len = ft_strlen(str) - (size_t)index - 1;
// 		dest = malloc(rest_len + 1);
// 		if (!dest) return (1);
// 	ft_copier_from(str + index + 1, dest, '\0');
	

// 	printf("Original string:\n%s\n", str);
// 	printf("Line (before newline):\n%s\n", line);
// 	printf("Dest (after newline):\n%s\n", dest);

// 	free(str);
// 	free(line);
// 	free(dest);
// 	return (0);
// }