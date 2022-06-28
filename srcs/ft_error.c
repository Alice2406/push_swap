/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:45:34 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/28 21:22:25 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	return (EXIT_FAILURE);
}

char	*ft_zero_spe(char *tab)
{
	char	*tmp;

	tmp = ft_strtrim(tab, "0-");
	tab = ft_strjoin("-", tmp);
	return (tab);
}

char	**check_zero(char **tab)
{
	int	i;
	int	size_tab;

	i = 0;
	size_tab = 0;
	while (tab[i++])
		size_tab++;
	i = 0;
	while (size_tab > 0)
	{
		if (tab[i][0] == '0' && tab[i][1] != '\0')
			tab[i] = ft_strtrim(tab[i], "0");
		else if (tab[i][0] == '+' && tab[i][1] == '0')
			tab[i] = ft_strtrim(tab[i], "0+");
		else if (tab[i][0] == '-' && tab[i][1] == '0')
			tab[i] = ft_zero_spe(tab[i]);
		i++;
		size_tab--;
	}
	return (tab);
}
