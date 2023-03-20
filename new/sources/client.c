#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
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

static void	signal_handler(int signal, siginfo_t *c_info, void *context)
{
	if (sa.s_pid != c_info->si_pid)
		return ;
	(void)signal;
	(void)context;
}

void	send_bit(int bit)
{
	if (bit)
	{
		if (kill(sa.s_pid, SIGUSR1) == -1)
			terminate(EXIT_FAILURE, "Server offline.");
	}
	else
	{
		if (kill(sa.s_pid, SIGUSR2) == -1)
			terminate(EXIT_FAILURE, "Server offline.");
	}
}

void	bit_to_binary(int pid, char byte)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(byte & (0x01 << bit));
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	
	i = 0;
	if (argc != 3)
		terminate(EXIT_FAILURE, "Invalid parameters, try ./client <PID> <string>");
	sa = (t_client_sa) {0};
	sa.s_pid = atoi(argv[1]);
	if (sa.s_pid <= 0)
		terminate(EXIT_FAILURE, "Invalid PID.");
	sa.sa.sa_sigaction = &signal_handler;
	sa.sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa.sa, NULL);
	sigaction(SIGUSR2, &sa.sa, NULL);
	while (argv[2][i] != '\0')
	{
		bit_to_binary(sa.s_pid, argv[2][i]);
		i++;
	}
	bit_to_binary(sa.s_pid, '\n');
	return (0);
}
