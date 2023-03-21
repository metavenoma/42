/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:09 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/21 16:40:48 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

t_client	g_client;

void	terminate(int status, char *error_msg)
{
	if (error_msg)
	{
		ft_printf("CLIENT ERROR: %s\n", error_msg);
	}
	exit(status);
}

void	send_bit(int bit)
{
	if (bit)
	{
		if (kill(g_client.pid, SIGUSR1) == -1)
			terminate(1, "server offline");
		usleep(100);
	}
	else
	{
		if (kill(g_client.pid, SIGUSR2) == -1)
			terminate(1, "server offline");
		usleep(100);
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_client.bit_acknowledged = 1;
}

void	byte_to_binary(char byte)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_client.bit_acknowledged = 0;
		send_bit(byte & (0x01 << i));
		while (!g_client.bit_acknowledged)
		{
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	static int	i;

	if (argc != 3)
	{
		terminate(1, "Wrong number of arguments");
	}
	g_client.pid = ft_atoi(argv[1]);
	if (g_client.pid <= 0)
		terminate(1, "Invalid PID.");
	g_client.sa.sa_flags = 1;
	signal(SIGUSR1, signal_handler);
	while (argv[2][i] != '\0')
	{
		byte_to_binary(argv[2][i]);
		i++;
	}
	byte_to_binary('\n');
	return (0);
}
