#include "get_next_line.h"

char	*get_line(int fd, char *stash)
{
	char	*buffer;
	int	i;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0 && !ft_strchr(stash, '\0'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	if (i == -1)
		return (NULL);
	return (stash);
}

char	*get_current_line(int static_i, char *stash)
{
	char	*temp;
	int	i;
	int	aux;
	
	i = 0;
	if (!stash[static_i])
		return (NULL);
	aux = static_i;
	while (stash[aux] != '\n' && stash[aux])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (stash[static_i] != '\n' && stash[static_i])
	{
		temp[i] = stash[static_i];
		i++;
		static_i++;
	}
	if (stash[static_i] == '\n')
	{
		temp[i] = '\n';
		static_i++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static int	i;
	char	*line;
	static char	*stash;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = get_line(fd, stash);
	if (!stash)
		return (NULL);
	line = get_current_line(i, stash);
	return (line);

}
