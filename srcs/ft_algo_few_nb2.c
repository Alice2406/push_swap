/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_few_nb2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:08:38 by aniezgod          #+#    #+#             */
/*   Updated: 2022/05/23 17:46:49 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_lst **a, t_lst **b)
{
	ft_reverse_rotate_a(a);
	ft_push_b(a, b);
	ft_push_b(a, b);
	ft_three_nb(a);
	ft_push_a(a, b);
	ft_rotate_a(a);
	ft_push_a(a, b);
}

int	*ft_lst_to_tab(t_lst *a, int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	i = 0;
	while (size != 0)
	{
		tab[i] = a->nb;
		i++;
		a = a->next;
		size--;
	}
	return (tab);
}

int	ft_length_plssc(int *tab, int size, int **new_tab)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * (size + 1));
	if (NULL == lis)
		return (0);
	lis[0] = 1;
	i = 0;
	while (++i < size)
	{
		lis[i] = 1;
		j = -1;
		while (++j < i)
			if (tab[i] > tab[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
	i = -1;
	j = 0;
	while (++i < size)
		if (lis[i] > j)
			j = lis[i];
	(*new_tab) = lis;
	return (j);
}

int	*ft_tab_plssc(int *tab, int max, int *lis)
{
	int	i;
	int	*plssc;

	plssc = malloc(sizeof(int) * (max + 1));
	i = 0;
	while (lis[i] != max)
		i++;
	plssc[max--] = tab[i];
	while (max > 0)
	{
		if (lis[i] == max)
		{
			plssc[max--] = tab[i];
		}
		i--;
	}
	return (plssc);
}

void	ft_compare_lst_tab(t_lst **a, t_lst **b, int *tab, int length)
{
	int	i;
	int	size;

	size = ft_lstsize_ps(*a);
	i = 1;
	while (size > 0)
	{
		if ((i == 2 && (*a)->nb < ft_lstlast2(*a)->nb)
			|| (i > 2 && (*a)->nb < ft_lstlast2(*a)->nb
				&& (*a)->nb > ft_lst_before_last(*a)->nb))
		{
			ft_reverse_rotate_a(a);
			ft_swap_a(a);
			ft_rotate_a(a);
			ft_rotate_a(a);
		}
		else if (tab[i] == (*a)->nb && i < length + 1)
		{
			i++;
			ft_rotate_a(a);
		}
		else
			ft_push_b(a, b);
		size--;
	}
}
