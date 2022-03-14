/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:33:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/14 15:33:38 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew2(int nb)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front2(t_lst **lst, int nb)
{
	t_lst	*new;

	new = ft_lstnew2(nb);
	new->next = *lst;
	*lst = new;
}

void	ft_lst_del_first(t_lst **lst)
{
	if ((*lst)->next)
		*lst = (*lst)->next;
	else
		*lst = NULL;
}