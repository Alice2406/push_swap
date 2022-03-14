/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:21:52 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/14 15:36:24 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap_a(t_lst **a)
{
    t_lst *tmp;

    if (ft_lstsize_ps(*a) < 2)
        return ;
    tmp = (*a)->next; //tmp = 2eme nb list
    (*a)->next = tmp->next; //2eme mb de la list = NULL
    tmp->next = (*a); //2eme tmp = 1nb de la list
    (*a) = tmp; // 1nb list = tmp 
}

void ft_push_a(t_lst **a, t_lst **b)
{
   if (ft_lstsize_ps(*b) == 0)
        return ;
    ft_lstadd_front2(a, (*b)->nb);
    ft_lst_del_first(b);
}
