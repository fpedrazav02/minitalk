/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:22:06 by fpedraza          #+#    #+#             */
/*   Updated: 2025/02/01 20:14:35 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

void	setup_signals(void);
void	start_message(void);

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		write(1, "\033[91mError:\033[0m wrong format.\n", 32);
		return (0);
	}
	start_message();
	setup_signals();
	while (1)
		pause();
	return (0);
}

void	start_message(void)
{
	int		pidn;
	char	*pid;
	char	*server_message;

	pidn = getpid();
	pid = ft_itoa(pidn);
	server_message = ft_strjoin(
			"[ \033[1;32mMinitalk\033[0m ] started with PID: ", pid);
	ft_putstr_fd(server_message, 1);
	ft_putstr_fd("\n -> Waiting for a new message...\n", 1);
	free(pid);
	free(server_message);
}

void	setup_signals(void)
{
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
}
