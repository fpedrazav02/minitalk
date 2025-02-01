/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:17:07 by fpedraza          #+#    #+#             */
/*   Updated: 2025/02/01 20:46:22 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

void	send_char_to_pid(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		bit++;
	}
}

void	send_str_to_pid(char *str, int pid)
{
	while (*str)
	{
		send_char_to_pid(*str, pid);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_putstr_fd("\033[91mError:\033[0m wrong client init format.\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_str_to_pid(str, pid);
	return (0);
}
