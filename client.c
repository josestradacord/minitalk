/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:29:41 by joestrad          #+#    #+#             */
/*   Updated: 2022/12/27 13:21:16 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/****************************************************************************	
 *  Function ft_get_ack
 *    @param signal		signal received from the server
 *    @return			this function doesn't return anything
 *  This function manage the signals received from the server to confirm the
 * transmision of the message
 * 
 *  If a SIGUSR1 signal is received the function increments the number of 
 * characters received, when a SIGUSR2 signal is received, the function prints 
 * the number of characters that have been received, and exits
*/
static void	ft_get_ack(int signal)
{
	static int	received = 0;

	if (signal == SIGUSR1)
		received++;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

/****************************************************************************	
 *  Function ft_send_msg
 *    @param pid	process id of the server
 *    @param str	msg to send to the server, is a char *
 *    @return		this function doesn't return anything
 *  This function sends the msg given to the process whom pid is given too
 * 
 *  The function sends the msg bit by bit. If a bit is 1, it sends the 
 * SIGUSR2 signal, if the bit is 0 the SIGUSR1 signal is send instead.
 *  To access at each bit it uses the >> operator, shifting the bits to the
 * right.
 *  The function uses the function kill(pid, signal) to send a bit to the server
 * 	Finally the function waits for a period of microseconds, with the usleep()
 * function.
*/
static void	ft_send_msg(int pid, char *str)
{
	int		bit;
	char	c;

	while (*str)
	{
		bit = 8;
		c = *str++;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	size_t	len;
	int		pid_nbr;

	if (argc > 1)
	{
		len = ft_strlen(argv[2]);
		pid_nbr = ft_atoi(argv[1]);
	}
	if (argc != 3 || !len || pid_nbr <= 0)
	{
		ft_putstr_fd("ERROR\nUsage: ./client <server's_pid> <message>\n", 1);
		return (1);
	}
	ft_putstr_fd("Sent: ", 1);
	ft_putnbr_fd(len, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, ft_get_ack);
	signal(SIGUSR2, ft_get_ack);
	ft_send_msg(pid_nbr, argv[2]);
	while (1)
		pause();
	return (0);
}
