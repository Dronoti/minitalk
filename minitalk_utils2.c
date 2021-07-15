/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:33:37 by bkael             #+#    #+#             */
/*   Updated: 2021/07/13 14:34:02 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	long long		num;
	long long		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + (nptr[i] - '0');
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (num * sign);
}

int	ft_receiver(int signum, void (*hdl)(int, siginfo_t *, void *))
{
	struct sigaction	s_act;

	s_act.sa_sigaction = hdl;
	sigemptyset(&s_act.sa_mask);
	s_act.sa_flags = SA_SIGINFO;
	return (sigaction(signum, &s_act, NULL));
}

void	ft_check_error(int send, int err, char **str)
{
	if (send == -1)
	{
		if (err == 'm')
			ft_putendl_fd("Error: malloc error", 2);
		else if (err == 's')
			ft_putendl_fd("Error: signal not sent from server", 2);
		else if (err == 'c')
			ft_putendl_fd("Error: signal not sent from client", 2);
		else if (err == 'r')
			ft_putendl_fd("Error: signal is not processed by the server", 2);
		else if (err == 'p')
			ft_putendl_fd("Error: signal is not processed by the client", 2);
		if (str && *str)
		{
			free(*str);
			*str = NULL;
		}
		exit(EXIT_FAILURE);
	}
}

void	ft_show_message(char **msg)
{
	ft_putendl_fd(*msg, 1);
	if (*msg)
	{
		free(*msg);
		*msg = NULL;
	}
}
