/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:58:11 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/08 21:11:19 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static int	g_ready = 0;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_ready = 1;
}

void	send_byte(int pid, char byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ready = 0;
		if (byte & 1)
			ft_send_signal(pid, SIGUSR1);
		else
			ft_send_signal(pid, SIGUSR2);
		byte >>= 1;
		i--;
		while (!g_ready)
			;
	}
}

void	send_str(int pid, char *str)
{
	while (*str)
		send_byte (pid, *(str++));
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("usage: ./client [pid server] [string] \n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1 || pid == 0)
	{
		ft_putstr("usage: ./client [pid server] [string] \n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, signal_handler);
	send_str(pid, argv[2]);
	return (0);
}
