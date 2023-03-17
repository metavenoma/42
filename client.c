#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		write(fd, &str[s], 1);
		s++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
}

void	terminate(int status, char *error_msg)
{
	if (error_msg)
	{
		ft_putendl_fd("+==========================================================+", 1);
		ft_putendl_fd("███    ███ ██ ███    ██ ██ ████████  █████  ██      ██   ██", 1);
		ft_putendl_fd("████  ████ ██ ████   ██ ██    ██    ██   ██ ██      ██  ██ ", 1);
		ft_putendl_fd("██ ████ ██ ██ ██ ██  ██ ██    ██    ███████ ██      █████  ", 1);
		ft_putendl_fd("██  ██  ██ ██ ██  ██ ██ ██    ██    ██   ██ ██      ██  ██  ", 1);
		ft_putendl_fd("██      ██ ██ ██   ████ ██    ██    ██   ██ ███████ ██   ██ ", 1);
		ft_putendl_fd("+==========================================================+", 1);
		ft_putstr_fd("      CLIENT ERROR: ", 1);
		ft_putendl_fd(error_msg, 2);
		ft_putendl_fd("+==========================================================+", 1);
	}
	exit(status);
}

/*void	bit_to_binary(int pid, char byte)
{
	
}*/

int	main(int argc, char **argv)
{
	if (argc != 3)
		terminate(EXIT_FAILURE, "Invalid parameters.");
}
