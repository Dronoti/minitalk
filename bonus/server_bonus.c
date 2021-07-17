/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:15:39 by bkael             #+#    #+#             */
/*   Updated: 2021/07/17 14:16:02 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_create_msg(char *txt, char c)
{
	int		i;
	char	*msg;

	if (!txt)
	{
		txt = (char *)malloc(sizeof(char));
		if (!txt)
			ft_check_error(-1, 'm', NULL);
		txt[0] = '\0';
	}
	i = ft_strlen(txt);
	msg = (char *)malloc(sizeof(char) * (i + 2));
	if (!msg)
		ft_check_error(-1, 'm', &txt);
	i = -1;
	while (txt[++i])
		msg[i] = txt[i];
	msg[i] = c;
	msg[++i] = '\0';
	free(txt);
	return (msg);
}

void	ft_getting(int signum, siginfo_t *siginfo, void *data)
{
	static char	c;
	static int	counter = 128;
	static char	*msg;
	int			send;

	data = NULL;
	send = 0;
	if (signum == SIGUSR1)
		c |= counter;
	counter >>= 1;
	if (!counter)
	{
		msg = ft_create_msg(msg, c);
		if (c == '\0')
		{
			ft_show_message(&msg);
			send = kill(siginfo->si_pid, SIGUSR2);
			ft_check_error(send, 's', &msg);
		}
		c = 0;
		counter = 128;
	}
}

int	main(void)
{
	int	send;

	if (getpid() == 0)
		exit(EXIT_FAILURE);
	ft_putstr_fd("The server is running\nPID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	send = ft_receiver(SIGUSR1, &ft_getting);
	send = ft_receiver(SIGUSR2, &ft_getting);
	ft_check_error(send, 'r', NULL);
	while (send != -1)
		pause();
	return (0);
}
