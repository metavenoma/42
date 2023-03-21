/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:00:42 by rverona-          #+#    #+#             */
/*   Updated: 2023/03/21 16:21:35 by rverona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_client
{
	struct sigaction	sa;
	int					bit_acknowledged;
	int					pid;
}	t_client;

void		terminate(int status, char *error_msg);
static void	signal_handler(int signal);
void		send_bit(int bit);
void		byte_to_binary(char byte);

#endif
