/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:58:58 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/05 11:39:36 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countchars(int n)
{
	size_t	len;
	int		number;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		else
		{
			len++;
			number = (-1) * n;
		}
	}
	else
		number = n;
	while (number > 9)
	{
		number /= 10;
		len++;
	}
	len++;
	return (len);
}

static int	ft_positive(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return (147483648);
		else
			return (-n);
	}
	else
		return (n);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;
	int		number;

	len = ft_countchars(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
	}
	else if (n < 0)
		res[0] = '-';
	number = ft_positive(n);
	while (number > 9)
	{
		res[len-- - 1] = (number % 10) + 48;
		number /= 10;
	}
	res[len - 1] = number + 48;
	res[ft_countchars(n)] = '\0';
	return (res);
}
