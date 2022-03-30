/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/30 01:44:28 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_few_arguments(t_lst **a)
{
	if (ft_lstsize_ps(*a) == 2 && ft_check_lst(*a) == 0)
		ft_swap_a(a);
	else if (ft_lstsize_ps(*a) == 3)
	{
		if ((*a)->nb < (*a)->next->nb && (*a)->next->nb
			> (*a)->next->next->nb && (*a)->nb > (*a)->next->next->nb)
			ft_reverse_rotate_a(a);
		else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb
			< (*a)->next->next->nb && (*a)->nb > (*a)->next->next->nb)
			ft_rotate_a(a);
		else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb
			< (*a)->next->next->nb && (*a)->nb < (*a)->next->next->nb)
			ft_swap_a(a);
		else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb
			> (*a)->next->next->nb && (*a)->nb > (*a)->next->next->nb)
		{
			ft_swap_a(a);
			ft_reverse_rotate_a(a);
		}
		else
		{
			ft_reverse_rotate_a(a);
			ft_swap_a(a);
		}
	}
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

	lis = malloc(sizeof(int) * size);
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

int *ft_tab_plssc(int *tab, int max, int *lis)
{
	int i;  
	int *plssc;

	plssc = malloc(sizeof(int) * max);
	i = 0;
	while (lis[i] != max)
		i++;
	plssc[max--] = tab[i];
//	ft_printf("plssc[%d] = %d\n", (max + 1), plssc[max + 1]);
	while (max > 0)
	{
		if (lis[i] == max)
		{
			plssc[max--] = tab[i];
//			ft_printf("plssc[%d] = %d\n", (max + 1), plssc[max + 1]);
		}
		i--;
	}
	return (plssc);
}
