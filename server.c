/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:36:22 by khhihi            #+#    #+#             */
/*   Updated: 2025/03/04 22:56:09 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include <unistd.h>

void ft_handler(int signum)
{
    static char byte;
    static int i;

    if (signum == SIGUSR1)
        byte |= (1 << (7 - i));
    i++;
    if (i == 8)
    {
        ft_putchar_fd(byte, 1);
        i = 0;
        byte = 0;
		write(1,"\n",1);
    }
	usleep(50);
}
int main(int ac, char **av)
{
	if (ac != 1)
		return (ft_putstr_fd("Error: wrong format.\nTry: ./server", 1), 1);
	ft_putstr_fd ("The pid of this server is : ", 1);
	ft_putnbr_fd (getpid(), 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		usleep(50);

}
