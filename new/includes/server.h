#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_server_sa
{
	struct sigaction	sa;
	char			byte;
}	t_server_sa;

void	terminate(int status, char *error_msg);
static void	signal_handler(int signal, siginfo_t *info, void *context);

#endif
