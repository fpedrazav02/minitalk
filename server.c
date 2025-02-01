/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:22:06 by fpedraza          #+#    #+#             */
/*   Updated: 2025/02/01 19:28:23 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"


void	ft_handler(int signal)
{

	static int bit;
	static int i;

	// Or bit operation when sent 1
	if (signal == SIGUSR1){
		i |= (0x01 << bit);
	}
	bit++;
	// If 8bits <-> 1byte -> print
	if (bit == 8){
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{

	int PID;

	(void)argv;
	if (argc != 1){
		write(1, "\033[91mError:\033[0m wrong format.\n", 21);
		return (0);
	}
	PID = getpid();
	char *pid = ft_itoa(PID);
	char *server_message = ft_strjoin("[ \033[1;32mMinitalk\033[0m ] started with PID: ", pid);
	ft_putstr_fd(server_message, 1);
	ft_putstr_fd("\n -> Waiting for a new message...\n", 1);
	free(pid);
	free(server_message);

	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while(1){
		pause();
	}

	return (0);
}
