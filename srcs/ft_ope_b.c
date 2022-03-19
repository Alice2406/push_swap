/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:26:24 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/19 17:53:17 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_lst **b)
{
	t_lst	*tmp;

	if (ft_lstsize_ps(*b) < 2)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
	ft_printf("sb\n");
}

void	ft_push_b(t_lst **a, t_lst **b)
{
	if (ft_lstsize_ps(*a) == 0)
		return ;
	ft_lstadd_front2(b, (*a)->nb);
	ft_lst_del_first(a);
	ft_printf("pb\n");
}

void	ft_rotate_b(t_lst **b)
{
	t_lst	*tmp;
	t_lst	*new;

	if (ft_lstsize_ps(*b) < 2)
		return ;
	new = ft_lstnew2((*b)->nb);
	tmp = (*b);
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			ft_lst_del_first(b);
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("rb\n");
}

void	ft_reverse_rotate_b(t_lst **b)
{
	t_lst	*tmp;

	tmp = ft_lstlast2(*b);
	ft_lstadd_front2(b, tmp->nb);
	ft_lst_del_last(b);
	ft_printf("rrb\n");
}
