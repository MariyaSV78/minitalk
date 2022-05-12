/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:23:09 by msosnova          #+#    #+#             */
/*   Updated: 2021/11/11 12:23:19 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	ft_send_signal(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}
