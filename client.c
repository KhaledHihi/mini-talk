/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:35 by khhihi            #+#    #+#             */
/*   Updated: 2025/03/08 21:33:35 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		g_confirmation = 0;

void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
		g_confirmation = 1;
	else if (signum == SIGUSR2)
	{
		ft_putendl_fd("The message was received successfully.", 1);
		exit(0);
	}
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 7;
	if (kill(pid, 0) < 0)
	{
		ft_putendl_fd("Invalid PID", 1);
		exit(EXIT_FAILURE);
	}
	while (bit >= 0)
	{
		g_confirmation = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (!g_confirmation)
			pause();
	}
}

void	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		send_bits(pid, msg[i++]);
	send_bits(pid, '\0');
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		ft_putendl_fd("Error: wrong format.\nTry: ./client <PID> <MESSAGE>", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (ft_putendl_fd("Invalid PID.", 1), 1);
	if (ft_strlen(av[2]) == 0)
		return (ft_putendl_fd("Error: Write a message", 1), 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	send_message(pid, av[2]);
	while (1)
		usleep(100);
}
