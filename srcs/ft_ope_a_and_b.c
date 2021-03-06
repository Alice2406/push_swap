/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_a_and_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:30:42 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/16 12:41:40 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_and_b(t_lst **a, t_lst **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
}

void	ft_rotate_a_and_b(t_lst **a, t_lst **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
}

void	ft_reverse_rotate_a_and_b(t_lst **a, t_lst **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
}
