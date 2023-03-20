#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int	g_stay;

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
		ft_putendl_fd("+=============================================================+", 1);
		ft_putendl_fd("  ███    ███ ██ ███    ██ ██ ████████  █████  ██      ██   ██", 1);
		ft_putendl_fd("  ████  ████ ██ ████   ██ ██    ██    ██   ██ ██      ██  ██ ", 1);
		ft_putendl_fd("  ██ ████ ██ ██ ██ ██  ██ ██    ██    ███████ ██      █████  ", 1);
		ft_putendl_fd("  ██  ██  ██ ██ ██  ██ ██ ██    ██    ██   ██ ██      ██  ██  ", 1);
		ft_putendl_fd("  ██      ██ ██ ██   ████ ██    ██    ██   ██ ███████ ██   ██ ", 1);
		ft_putendl_fd("+=============================================================+", 1);
		ft_putstr_fd(" CLIENT ERROR: ", 1);
		ft_putendl_fd(error_msg, 2);
		ft_putendl_fd("+=============================================================+", 1);
	}
	exit(status);
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_stay = 0;
	else
		printf("Message sent successfully\n");
}

void	bit_to_binary(int pid, char byte)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (g_stay == 0)
		{
			g_stay = 1;
			if ((byte & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else 
				kill(pid, SIGUSR2);
			usleep(100);
		}
		bit++;	
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	mt;
	int	i;
	int	pid;
	
	g_stay = 0;
	i = 0;
	if (argc != 3)
		terminate(EXIT_FAILURE, "Invalid parameters, try ./client <PID> <string>");
	pid = atoi(argv[1]);
	if (pid <= 0)
		terminate(EXIT_FAILURE, "Invalid PID.");
	mt = (struct sigaction) {0};
	mt.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &mt, NULL);
	sigaction(SIGUSR2, &mt, NULL);
	while (argv[2][i] != '\0')
	{
		bit_to_binary(pid, argv[2][i]);
		i++;
	}
	bit_to_binary(pid, '\n');
	return (0);
}
