/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:58:24 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/03 11:24:02 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnb_rec(int n, int fd)
{
	if (n > 9)
	{
		ft_printnb_rec(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_printnb_rec((-1) * (n / 10), fd);
			ft_putchar_fd((-1) * (n % 10) + 48, fd);
		}
		else
			ft_printnb_rec((-1) * n, fd);
	}
	else
		ft_printnb_rec(n, fd);
}
