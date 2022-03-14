/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:26:24 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/14 15:36:31 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap_b(t_lst **b)
{
    t_lst *tmp;

    if (ft_lstsize_ps(*b) < 2)
        return ;
    tmp = (*b)->next;
    (*b)->next = tmp->next;
    tmp->next = (*b);
    (*b) = tmp;
}

void ft_push_b(t_lst **a, t_lst **b)
{
    if (ft_lstsize_ps(*a) == 0)
        return ;
    ft_lstadd_front2(b, (*a)->nb);
    ft_lst_del_first(a);
}