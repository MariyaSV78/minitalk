/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:46:09 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/06 09:46:13 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minitalk.h>

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	write(1, (void *)str, i);
}
