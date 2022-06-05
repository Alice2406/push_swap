/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:58:48 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/05 14:10:43 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_part(t_lst **a, t_lst **b, int med_sup)
{
	int	size;

	size = ft_lstsize_ps(*a);
	while (size != 0)
	{
		if ((*a)->nb <= med_sup)
			ft_push_b(a, b);
		else
			ft_rotate_a(a);
		size--;
	}
}

int	ft_find_smallest(t_lst *b)
{
	int		smallest;
	t_lst	*tmp;

	tmp = b;
	smallest = tmp->nb;
	tmp = tmp->next;
	while (tmp)
	{
		if (smallest > tmp->nb)
			smallest = tmp->nb;
		tmp = tmp->next;
	}
	return (smallest);
}

int	ft_find_biggest(t_lst *b)
{
	int		biggest;
	t_lst	*tmp;

	tmp = b;
	biggest = tmp->nb;
	tmp = tmp->next;
	while (tmp)
	{
		if (biggest < tmp->nb)
			biggest = tmp->nb;
		tmp = tmp->next;
	}
	return (biggest);
}

void	ft_tri_part(t_lst **a, t_lst **b)
{
	int	smallest;
	int	biggest;

	while (ft_lstsize_ps(*b) != 0)
	{
		smallest = ft_find_smallest(*b);
		biggest = ft_find_biggest(*b);
		if (ft_compare_place(smallest, biggest, (*b)) == 0)
		{
			ft_b_push(biggest, b);
			ft_push_a(a, b);
		}
		else
		{
			ft_b_push(smallest, b);
			ft_push_a(a, b);
			ft_rotate_a(a);
		}
	}
}

void	ft_algo(t_lst **a, t_lst **b)
{
	int	median;
	int	median_sup;
	int	median_inf;

	median = ft_median(*a);
	median_sup = half_median_sup(*a, median);
	median_inf = half_median_inf(*a, median);
	ft_first_part(a, b, median_sup);
	ft_tri_part(a, b);
	ft_between_part(a, b, median_sup, median);
	ft_tri_part(a, b);
	ft_between_part(a, b, median, median_inf);
	ft_tri_part(a, b);
	ft_finish_part(a, b, median_inf);
	ft_tri_part2(a, b);
}
