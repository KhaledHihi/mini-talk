/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:36:22 by khhihi            #+#    #+#             */
/*   Updated: 2025/03/03 20:29:37 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int main()
{
	ft_putstr_fd ("The pid of this server is : ", 1);
	ft_putnbr_fd (getpid(), 1);
	write(1, "\n", 1);
	while (1)
		usleep(50);
}
