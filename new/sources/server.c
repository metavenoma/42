#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_server_sa 
{
	struct sigaction	sa;
	char			byte;
}	t_server_sa;

t_server_sa	sa;

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
void    terminate(int status, char *error_msg) 
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
		ft_putstr_fd("      SERVER ERROR: ", 1);
	ft_putendl_fd(error_msg, 2);
		ft_putendl_fd("+==========================================================+", 1);
	}
	exit(status);
}
static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;

	(void)context;
	if (signal == SIGUSR1)
		sa.byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", sa.byte);
		bit = 0;
		sa.byte = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char *argv[])
{
	sa.sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa.sa_mask);
	sa.sa.sa_flags = SA_SIGINFO;
	(void)argv;
	if (argc != 1)
		terminate(EXIT_FAILURE, "Invalid parameters, try ./server");
	printf("PID: %d\n", getpid());
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa.sa, NULL);
		sigaction(SIGUSR2, &sa.sa, NULL);
		pause ();
	}
	return (0);
}
