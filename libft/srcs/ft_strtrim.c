/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:01:30 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/28 21:22:57 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static unsigned int	find_start(char const *s1, char const *set)
{
	unsigned int	start;
	int				i;

	start = 0;
	i = 0;
	while (s1[i])
	{
		if (is_charset(s1[i], set) == 1)
		{
			start++;
			i++;
		}
		else
			return (start);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	str = ft_substr(s1, start, ft_strlen(s1) - start);
	return (str);
}
