/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:19:07 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/24 11:22:52 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

void	terminate(int status, char *error_msg)
{
	if (error_msg)
	{
		ft_putstr_fd("SERVER ERROR: ", 1);
		ft_putendl_fd(error_msg, 2);
	}
	exit(status);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	byte;

	(void)context;
	if (signal == SIGUSR1)
		byte |= (0x01 << bit);
	if (bit == 7)
	{
		if (byte)
			ft_putchar_fd(byte, 1);
		bit = 0;
		byte = 0;
	}
	else
		bit++;
	if (kill(info->si_pid, SIGUSR1))
		terminate(1, "Error communicating with Client.");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	(void)argv;
	if (argc != 1)
		terminate(EXIT_FAILURE, "Invalid parameters, try ./server");
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argc == 1)
	{
		pause ();
	}
	return (0);
}
