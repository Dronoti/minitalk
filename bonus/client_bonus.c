/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:14:59 by bkael             #+#    #+#             */
/*   Updated: 2021/07/17 14:15:19 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_sending(int pid, char *message)
{
	int	i;
	int	counter;
	int	send;

	i = -1;
	while (i == -1 || message[i])
	{
		i++;
		counter = 128;
		while (counter)
		{
			if (counter & message[i])
				send = kill(pid, SIGUSR1);
			else
				send = kill(pid, SIGUSR2);
			ft_check_error(send, 'c', NULL);
			counter >>= 1;
			usleep(100);
		}
	}
}

void	ft_check_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putendl_fd("Error: wrong numbers of arguments", 2);
		exit(EXIT_FAILURE);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putendl_fd("Error: wrong PID", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_confirm(int signum, siginfo_t *siginfo, void *data)
{
	siginfo = NULL;
	data = NULL;
	if (signum == SIGUSR2)
	{
		ft_putendl_fd("Message received successfully", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int	send;

	ft_check_arg(argc, argv);
	send = ft_receiver(SIGUSR2, &ft_confirm);
	ft_check_error(send, 'p', NULL);
	ft_sending(ft_atoi(argv[1]), argv[2]);
	pause();
	return (0);
}
