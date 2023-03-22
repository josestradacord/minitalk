/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:39:58 by joestrad          #+#    #+#             */
/*   Updated: 2022/10/05 11:37:00 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			words++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (words);
}

static char	**ft_free(char **str, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
		free(str[index++]);
	free(str);
	return (NULL);
}

static char	**ft_mysplit(char const *s, char c,	size_t strs, size_t start)
{
	char	**res;
	size_t	end;
	size_t	num_strs;

	num_strs = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (num_strs + 1));
	if (!res)
		return (NULL);
	while (s[start] != '\0' && num_strs-- > 0)
	{
		while (s[start] != '\0' && s[start] == c)
			start++;
		end = start;
		while (s[end] != '\0' && s[end] != c)
			end++;
		res[strs++] = ft_substr(s, start, end - start);
		if (res[strs - 1] == NULL)
			return (ft_free(res, strs - 1));
		start = end;
	}
	res[strs] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	return (ft_mysplit(s, c, 0, 0));
}
