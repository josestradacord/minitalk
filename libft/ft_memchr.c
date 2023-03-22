/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:44:49 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/05 11:21:15 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (n > 0)
	{
		str = (unsigned char *)s;
		i = 0;
		while (i < n)
		{
			if (*str == (unsigned char)c)
				return (str);
			str++;
			i++;
		}
		return (NULL);
	}
	return (NULL);
}
