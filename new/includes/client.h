#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_client_sa
{
	struct sigaction	sa;
	int			s_pid;
}	t_client_sa;

void	terminate(int status, char *error_msg);
static void	signal_handler(int signal, siginfo_t *c_info, void *context);
void	send_bit(int bit);
void	bit_to_binary(int pid, char byte);

#endif
