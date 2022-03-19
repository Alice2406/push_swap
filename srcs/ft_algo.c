/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/19 17:50:28 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_lst **a, t_lst **b)
{
	int place;
	int nb_ope;
	
	ft_push_b(a, b);
	ft_push_b(a, b);
	nb_ope = 2;
	if ((*b)->nb < (*b)->next->nb)
	{
		ft_swap_b(b);
		nb_ope++;
	}
	while (ft_lstsize_ps(*a) != 0)
	{
		place = 0;
		while (((*a)->nb < (*b)->nb) && (place < ft_lstsize_ps(*b)))
		{
			place++;
			ft_rotate_b(b);
			nb_ope++;
		}
		ft_push_b(a, b);
		while (place != 0)
		{
			ft_reverse_rotate_b(b);
			place--;
			nb_ope++;
		}
	}
	while (ft_lstsize_ps(*b) != 0)
	{
		ft_push_a(a, b);
		nb_ope++;
	}
//	ft_printf("%d\n", nb_ope);
}