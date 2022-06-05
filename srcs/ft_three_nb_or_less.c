/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_nb_or_less.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/05 14:18:50 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_which_sorting(t_lst **a, t_lst **b)
{
	if (ft_lstsize_ps(*a) == 2)
		ft_swap_a(a);
	else if (ft_lstsize_ps(*a) == 3)
		ft_three_nb(a);
	else if (ft_lstsize_ps(*a) == 5)
		ft_algo_for_5(a, b);
	else if (ft_lstsize_ps(*a) == 6)
		ft_algo_for_6(a, b);
	else
		ft_algo(a, b);
}

void	ft_three_nb(t_lst **a)
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
