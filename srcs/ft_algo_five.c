/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:30:49 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/28 19:00:24 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_place(t_lst *a, int b)
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

void	ft_insertion_first(t_lst **a, t_lst **b)
{
	int	place;

	place = ft_place(*a, (*b)->nb);
	if (place == 0)
		ft_push_a(a, b);
	else if (place == 3)
	{
		ft_push_a(a, b);
		ft_rotate_a(a);
	}
	else if (place == 1)
	{
		ft_rotate_a(a);
		ft_push_a(a, b);
		ft_reverse_rotate_a(a);
	}
	else if (place == 2)
	{
		ft_reverse_rotate_a(a);
		ft_push_a(a, b);
		ft_rotate_a(a);
		ft_rotate_a(a);
	}
}

void	ft_insertion_second(t_lst **a, t_lst **b)
{
	int	place;

	place = ft_place(*a, (*b)->nb);
	if (place == 0)
		ft_push_a(a, b);
	else if (place == 4)
	{
		ft_push_a(a, b);
		ft_rotate_a(a);
	}
	else if (place <= 2)
	{
		while ((*b)->nb > (*a)->nb)
			ft_rotate_a(a);
		ft_push_a(a, b);
		while (ft_check_lst(*a) == 0)
			ft_reverse_rotate_a(a);
	}
	else if (place == 3)
	{
		ft_reverse_rotate_a(a);
		ft_push_a(a, b);
		ft_rotate_a(a);
		ft_rotate_a(a);
	}
}

void	ft_algo_for_5(t_lst **a, t_lst **b)
{
	ft_push_b(a, b);
	ft_push_b(a, b);
	if (ft_check_lst(*a) == 0)
		ft_three_nb(a);
	ft_insertion_first(a, b);
	ft_insertion_second(a, b);
}

void	ft_algo_for_4(t_lst **a, t_lst **b)
{
	ft_push_b(a, b);
	if (ft_check_lst(*a) == 0)
		ft_three_nb(a);
	ft_insertion_first(a, b);
}
