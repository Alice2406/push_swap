/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/21 17:56:27 by aniezgod         ###   ########.fr       */
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

int	ft_place(t_lst *a, t_lst *b)
{
	int	place;

	place = 0;
	while ((a->nb < b->nb) && (place < ft_lstsize_ps(b)))
		place++;
	return (place);
}

int	ft_half_size_lst(t_lst *b)
{
	int	n;
	
	if
}

void	ft_algo(t_lst **a, t_lst **b)
{
	int place;
	int	n;
	
	if (ft_check_lst(*a) == 1)
		return ;
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
		place = ft_place(*a, *b);
		n = ft_lstsize_ps(*b);
		ft_push_b(a, b);
		while (place != 0)
		{
			ft_reverse_rotate_b(b);
			place--;
		}
	}
	while (ft_lstsize_ps(*b) != 0)
	{
		ft_push_a(a, b);
	}
}