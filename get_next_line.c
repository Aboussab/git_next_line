/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussab <aboussab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:18:22 by aboussab          #+#    #+#             */
/*   Updated: 2025/12/28 18:11:09 by aboussab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_switch_var(char **str)
{
	char	*tmp;
	char	*line;
	int		i;

	i = ft_split(*str);
	if (i >= 0)
	{
		line = (char *)malloc(i + 2);
		i = (ft_strlen(*str) - i);
		tmp = (char *)malloc(i + 1);
		if (!line || !tmp)
			return (NULL);
		line = ft_copier_from(*str, line, '\n');
		tmp = ft_copier_from(*str + ft_split(*str) + 1, tmp, '\0');
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

//hadii hya akheir we7da tesetit fiha norminet ok o 0leak 
//o all good cloniha o pushi 
void	allocate_buffer(char **buffer, int fd, ssize_t *r)
{
	*buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buffer)
	{
		*buffer = NULL;
		return ;
	}
	*r = read(fd, *buffer, BUFFER_SIZE);
	if (*r > 0)
		(*buffer)[*r] = '\0';
	else
	{
		free(*buffer);
		*buffer = (char *)malloc(1);
		*buffer[0] = '\0';
	}
}

void	free_buffer(char **buffer)
{
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	ssize_t			r;

	r = 1;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		allocate_buffer(&buffer, fd, &r);
	while (r > 0)
	{
		if (ft_split(buffer) < 0)
		{
			allocate_buffer(&tmp, fd, &r);
			buffer = ft_strjoin(&buffer, &tmp);
			if (!buffer)
				return (free(tmp), NULL);
		}
		else
			return (ft_switch_var(&buffer));
	}
	if (r == 0 && ft_strlen(buffer) > 0)
		return (free(tmp), ft_switch_var(&buffer));
	return (free_buffer(&buffer), free(tmp), NULL);
}
