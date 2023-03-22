/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:22:39 by joestrad          #+#    #+#             */
/*   Updated: 2022/12/16 11:28:03 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/****************************************************************************
 *  Function ft_read_bit
 *    @param signal		signal received
 *    @param info		pointer to a struct with information of the signal
 *    @param context	void pointer, necesary for queued signals
 *    @return			this function doesn't return anything
 *  This function receive each bit of the bytes the server is receiving and
 * writes the byte (char) on the output.
 * 
 *  This is the function that does the treatment of the signals that the server
 * is receiving (SIGUSR1 signal or SIGUSR2 signal).
 *  When it finished the reception it sends the client the acknowledgement (ack)
 * of the received message
*/
static void	ft_read_bit(int signal, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (signal == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			ft_putchar_fd('\n', 1);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(int argc, char *argv[])
{
	int					pid_nbr;
	struct sigaction	s_sigaction;
	size_t				len;

	len = ft_strlen(argv[0]);
	if (argc != 1 || !len)
	{
		ft_putstr_fd("ERROR\nUsage: ./server\n", 1);
		return (1);
	}
	pid_nbr = getpid();
	ft_putstr_fd ("Welcome to the minitalk server\n", 1);
	ft_putstr_fd("The server PID is: ", 1);
	ft_putnbr_fd(pid_nbr, 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_read_bit;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
