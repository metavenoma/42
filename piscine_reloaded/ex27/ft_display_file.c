/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <rverona-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:50:01 by rverona-          #+#    #+#             */
/*   Updated: 2022/08/31 22:20:21 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	buf;

	if (argc != 2)
	{
		if (argc < 2)
			write(1, "File name missing.\n", 19);
		else
			write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write (1, "Invalid file\n", 13);
		return (0);
	}
	while (read(fd, &buf, 1) != 0)
	{
		write(1, &buf, 1);
	}
	close(fd);
	return (0);
}
