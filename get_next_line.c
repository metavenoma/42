/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:08:36 by rverona-          #+#    #+#             */
/*   Updated: 2022/11/27 02:02:25 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		i;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0 && !ft_strchr(stash, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		if (temp)
			free (temp);
	}
	free (buffer);
	return (stash);
}

char	*get_current_line(char *stash)
{
	char	*temp;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	temp = malloc(sizeof(char) * i + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		temp[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		temp[i] = stash[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*extra_letters(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if ((stash[i] == '\n' && stash[i + 1] == '\0') || !stash[i])
	{
		free (stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	i++;
	if (!str)
		return (NULL);
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free (stash);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_line(fd, stash);
	if (!stash)
		return (NULL);
	line = get_current_line(stash);
	stash = extra_letters(stash);
	return (line);
}
