/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:35 by khhihi            #+#    #+#             */
/*   Updated: 2025/03/03 20:19:29 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

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
}
