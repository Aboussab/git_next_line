/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussab <aboussab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:37:18 by aboussab          #+#    #+#             */
/*   Updated: 2025/12/27 09:37:18 by aboussab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_split(char *str)
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

char	*ft_strjoin(char  **s1, char  **s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(*s2));
	if (!s2)
		return (ft_strdup(*s1));
	s = (char *)malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while ((*s1)[j] != 0)
		s[i++] = (*s1)[j++];
	j = 0;
	while ((*s2)[j] != 0)
		s[i++] = (*s2)[j++];
	s[i] = '\0';
	free(*s1);
	*s1 = NULL;
	return (free(*s2),*s2 = NULL,s);
}
char	*ft_copier_from(char *src, char *dest, char c)
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
	if (src[i] == '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
