/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:28:38 by aniezgod          #+#    #+#             */
/*   Updated: 2022/05/18 19:16:37 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_between_part(t_lst **a, t_lst **b, int med_sup, int med_inf)
{
	while ((*a)->nb <= med_sup)
		ft_rotate_a(a);
	while ((*a)->nb != med_sup)
	{
		if ((*a)->nb <= med_inf && (*a)->nb > med_sup)
			ft_push_b(a, b);
		else
			ft_rotate_a(a);
	}
	ft_rotate_a(a);
}

void	ft_finish_part(t_lst **a, t_lst **b, int med_sup)
{
	while ((*a)->nb <= med_sup)
		ft_rotate_a(a);
	while ((*a)->nb > med_sup)
	{
		if ((*a)->nb <= med_sup)
			break ;
		ft_push_b(a, b);
	}
}

void	ft_tri_part2(t_lst **a, t_lst **b)
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
	while (ft_check_lst(*a) != 1)
		ft_rotate_a(a);
}
