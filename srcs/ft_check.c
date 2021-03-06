/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:03:31 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/28 21:13:01 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ')
			i++;
		else if ((str[i] == '+' && ft_isdigit(str[i + 1]))
			|| (str[i] == '-' && ft_isdigit(str[i + 1])))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_int(char **str)
{
	int		i;
	int		j;
	long	nb;

	i = 0;
	while (str[i])
	{
		if (!ft_str_is_digit(str[i]))
			return (0);
		j = 0;
		while (str[i][j])
		{
			if (j > 11)
				return (0);
			j++;
		}
		nb = ft_atol(str[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_lst(t_lst *a)
{
	while (a)
	{
		if ((a->next != NULL) && (a->nb < a->next->nb))
			a = a->next;
		else if (a->next == NULL)
			return (1);
		else
			return (0);
	}
	return (1);
}

char	*arg_join(char **argv)
{
	char	*tab_arg;
	char	*tmp_ptr;
	int		i;

	i = 2;
	if (argv[1])
		tab_arg = ft_strjoin(argv[1], " ");
	while (argv[i])
	{
		tmp_ptr = tab_arg;
		tab_arg = ft_strjoin(tab_arg, argv[i]);
		free(tmp_ptr);
		if (argv[i + 1] != NULL)
		{
			tmp_ptr = tab_arg;
			tab_arg = ft_strjoin(tab_arg, " ");
			free(tmp_ptr);
		}
		i++;
	}
	return (tab_arg);
}
