/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussab <aboussab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:18:03 by aboussab          #+#    #+#             */
/*   Updated: 2025/12/27 14:18:03 by aboussab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char*	ft_extract_line(char** str)
{
	char*	tmp;
	char*	line;
	int		i;

	i = ft_split(*str);
	line = (char*)malloc(i + 2);
	i =(ft_strlen(*str) - i);
	tmp =  (char*)malloc(i + 1);
	if (!line || !tmp)
		return (NULL);
	line = ft_copier_from(*str, line,'\n');
	tmp = ft_copier_from(*str + (ft_split(*str) + 1), tmp,'\0');
	free(*str);
	*str = tmp;
	return (line);
}
void	allocate_buffer(char **buffer, int fd, size_t *r)
{
	*buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buffer)
	{
		*buffer = NULL;
		return ;
	}
	*r = read(fd, *buffer, BUFFER_SIZE);
	if (*r != 0)
		(*buffer)[*r] = '\0';
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
} 
char	*ft_last_line(char **buffer)
{
	char	*tmp;
	tmp = ft_strdup(*buffer);
	free(*buffer);
	*buffer = NULL;
	return(tmp);
}

char*	get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	size_t 	r;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		allocate_buffer(&buffer, fd, &r);
	while (r > 0)
	{
		if (ft_split(buffer) < 0)
		{
			allocate_buffer(&tmp, fd, &r);
			buffer = ft_strjoin(&buffer,&tmp);
			if (!buffer)
				return (NULL);
		}
		else
			return (ft_extract_line(&buffer));
	}
	if (r == 0 && buffer)
		return(ft_last_line(&buffer));
    return (NULL);
}

