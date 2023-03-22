/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:27:38 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/05 11:25:23 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos1;
	size_t	pos2;

	if (len >= 0)
	{
		pos1 = 0;
		if (needle[pos1] == '\0')
			return ((char *)haystack);
		while (haystack[pos1] != '\0' && pos1 < len)
		{
			pos2 = 0;
			while (haystack[pos1 + pos2] == needle[pos2] && \
					haystack[pos1 + pos2] != '\0' && (pos1 + pos2) < len)
			{
				if (needle[pos2 + 1] == '\0')
					return ((char *)&haystack[pos1]);
				pos2++;
			}	
			pos1++;
		}
	}
	return (NULL);
}
