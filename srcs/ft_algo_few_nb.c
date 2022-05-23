/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_few_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:57:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/05/23 20:55:07 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_half_size(t_lst *a)
{
	int	i;

	i = ft_lstsize_ps(a);
	if (i % 2 == 0)
		i = i / 2;
	else
		i = (i + 1) / 2;
	return (i);
}

int	ft_place_a(t_lst *a, int b)
{
	int	i;
	int	size;

	size = ft_lstsize_ps(a);
	i = 0;
	while (size > 0 && b > a->nb)
	{
		i++;
		a = a->next;
		size--;
	}
	return (i);
}

void	ft_split_insertion(int place, int size, t_lst **a, t_lst **b)
{
	int	half_size;
	int	reverse;

	half_size = ft_lst_half_size(*a);
	reverse = place;
	if (place <= half_size)
	{
		while (place-- > 0)
			ft_rotate_a(a);
		ft_push_a(a, b);
		while (reverse-- > 0)
			ft_reverse_rotate_a(a);
	}
	else if (place > half_size)
	{
		place = size - place;
		reverse = place;
		while (place-- > 0)
			ft_reverse_rotate_a(a);
		ft_push_a(a, b);
		while (reverse-- >= 0)
			ft_rotate_a(a);
	}
}

void	ft_insertion(t_lst **a, t_lst **b)
{
	int	place;
	int	size;

	size = ft_lstsize_ps(*a);
	while (*b)
	{
		place = ft_place_a(*a, (*b)->nb);
		if (place == 0)
			ft_push_a(a, b);
		else
			ft_split_insertion(place, size, a, b);
		size++;
	}
}

void	ft_algo_for_5(t_lst **a, t_lst **b)
{
	int	length_plssc;
	int	*tab;
	int	*plssc;
	int	*new_tab;
	int	size;

	size = ft_lstsize_ps(*a);
	tab = ft_lst_to_tab(*a, size);
	length_plssc = ft_length_plssc(tab, size, &new_tab);
	if (length_plssc == 1)
		ft_reverse(a, b);
	else
	{
		plssc = ft_tab_plssc(tab, length_plssc, new_tab);
		ft_compare_lst_tab(a, b, plssc, length_plssc);
		ft_insertion(a, b);
	}
}
