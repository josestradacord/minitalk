/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:35:11 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/03 16:42:10 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		pos;
	int		signo;
	int		res;

	pos = 0;
	signo = 1;
	res = 0;
	while (ft_is_space(str[pos]))
		pos++;
	if (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			signo *= -1;
		pos++;
	}
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = (str[pos] - '0') + (res * 10);
		pos++;
	}
	return (signo * res);
}
