/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:35:23 by aniezgod          #+#    #+#             */
/*   Updated: 2022/05/18 19:18:49 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_place(t_lst *b, int nb)
{
	t_lst	*tmp;
	int		size;
	int		rotate;

	rotate = 0;
	size = ft_lstsize_ps(b);
	tmp = b;
	while (tmp->nb != nb)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (size - rotate < rotate)
		rotate = size - rotate;
	return (rotate);
}

int	ft_rrb_or_rb(t_lst *b, int nb)
{
	t_lst	*tmp;
	int		size;
	int		rotate;

	rotate = 0;
	size = ft_lstsize_ps(b);
	tmp = b;
	while (tmp->nb != nb)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (size - rotate < rotate)
		return (1);
	return (0);
}

int	ft_compare_place(int smallest, int biggest, t_lst *b)
{
	int	place_s;
	int	place_b;

	place_s = ft_find_place(b, smallest);
	place_b = ft_find_place(b, biggest);
	if (place_s >= place_b)
		return (0);
	return (1);
}

void	ft_b_push(int nb, t_lst **b)
{
	if (ft_rrb_or_rb((*b), nb) == 0)
		while ((*b)->nb != nb)
			ft_rotate_b(b);
	else
		while ((*b)->nb != nb)
			ft_reverse_rotate_b(b);
}
