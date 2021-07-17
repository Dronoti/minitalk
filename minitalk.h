/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:10:39 by bkael             #+#    #+#             */
/*   Updated: 2021/07/15 14:11:40 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int ch);
int		ft_atoi(const char *nptr);
int		ft_receiver(int signum, void (*hdl)(int, siginfo_t *, void *));
void	ft_check_error(int send, int err, char **str);
void	ft_show_message(char **msg);
void	ft_getting(int signum, siginfo_t *siginfo, void *data);
void	ft_sending(int pid, char *message);
void	ft_check_arg(int argc, char **argv);
char	*ft_create_msg(char *txt, char c);
void	ft_confirm(int signum, siginfo_t *siginfo, void *data);

#endif