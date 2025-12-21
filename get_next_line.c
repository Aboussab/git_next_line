#include "get_next_line.h"

int	ft_contain(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	
	return (0);
}

char*	get_next_line(int fd)
{
	static char*	buffer;
	char*			tmp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer = read(fd, buffer, BUFFER_SIZE);
	while (ft_contain(buffer, '\n'))
	{
		tmp = 
	}

	


}



int main()
{
	int i = 0;
	int i;
	read(fd, buffer, BUFFER_SIZE);
	return (0);
}