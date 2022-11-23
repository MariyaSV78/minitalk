/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:23:16 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/09 09:23:20 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>

void	get_byte(int signal, siginfo_t *info, void *context)
{
	static unsigned char	byte = 0;
	static unsigned char	tmp_byte = 1;

	(void) context;
	if (signal == SIGUSR1)
		byte |= tmp_byte;
	tmp_byte <<= 1;
	if (tmp_byte == 0)
	{	
		ft_putchar(byte);
		byte = 0;
		tmp_byte = 1;
	}
	ft_send_signal(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	ft_putstr("server pid: ");
	ft_putnbr(pid);
	write (1, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = get_byte;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause ();
	return (0);
}
