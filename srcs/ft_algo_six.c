/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_six.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:13:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/05 14:17:30 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion_last(t_lst **a, t_lst **b)
{
	int	size;

	size = ft_lstsize_ps(*a);
	while (size > 0 && (*b)->nb > (*a)->nb)
	{
		ft_rotate_a(a);
		size--;
	}
	ft_push_a(a, b);
	while (ft_check_lst(*a) != 1)
		ft_rotate_a(a);
}

void	ft_algo_for_6(t_lst **a, t_lst **b)
{
	ft_push_b(a, b);
	ft_push_b(a, b);
	ft_push_b(a, b);
	if (ft_check_lst(*a) == 0)
		ft_three_nb(a);
	ft_insertion_first(a, b);
	ft_insertion_second(a, b);
	ft_insertion_last(a, b);
}
