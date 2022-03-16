/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:21:52 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/16 12:41:34 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_lst **a)
{
	t_lst	*tmp;

	if (ft_lstsize_ps(*a) < 2)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
}

void	ft_push_a(t_lst **a, t_lst **b)
{
	if (ft_lstsize_ps(*b) == 0)
		return ;
	ft_lstadd_front2(a, (*b)->nb);
	ft_lst_del_first(b);
}

void	ft_rotate_a(t_lst **a)
{
	t_lst	*tmp;
	t_lst	*new;

	if (ft_lstsize_ps(*a) < 2)
		return ;
	new = ft_lstnew2((*a)->nb);
	tmp = (*a);
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			ft_lst_del_first(a);
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_reverse_rotate_a(t_lst **a)
{
	t_lst	*tmp;

	tmp = ft_lstlast2(*a);
	ft_lstadd_front2(a, tmp->nb);
	ft_lst_del_last(a);
}
