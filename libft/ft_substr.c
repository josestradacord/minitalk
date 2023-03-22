/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:36:37 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/05 11:32:51 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	size_t			len_s;
	size_t			len_dest;

	len_s = ft_strlen(s);
	if (start > len_s || len_s == 0)
		len_dest = 0;
	else if ((len_s - start) >= len)
		len_dest = len;
	else
		len_dest = len_s - start;
	dest = (char *)ft_calloc((len_dest + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len_dest)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
