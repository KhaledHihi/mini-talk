/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:35 by khhihi            #+#    #+#             */
/*   Updated: 2025/03/04 23:04:36 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"



void	send_bits(int pid, char c)
{
	int bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		bit--;
		usleep(50);
	}
}

void	send_message(int pid, char *msg)
{
	static int	i;

	i = 0;
	while (msg[i])
		send_bits(pid, msg[i++]);
	kill(pid, SIGUSR2);
}
int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
		return (ft_putendl_fd("Error: wrong format.\nTry: ./client <PID> <MESSAGE>", 1), 1);
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (ft_putendl_fd("invalid pid ", 1), 1);
	if (ft_strlen(av[2]) == 0)
		return (ft_putendl_fd("Write a message", 1), 1);
	send_message(pid, av[2]);
}
