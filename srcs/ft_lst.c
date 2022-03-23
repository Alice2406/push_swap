/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:18:05 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/22 00:41:45 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnext(int content)
{
	t_lst	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nb = content;
	list->next = NULL;
	return (list);
}

t_lst	*ft_lstlast2(t_lst *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_lst	*ft_lst_before_last(t_lst *lst)
{
	while (lst)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_lstadd_back2(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	tmp = (*lst);
	if (!tmp)
		(*lst) = new;
	while (tmp)
	{
		if (tmp->nb == new->nb)
		{
			ft_error();
			return (0);
		}
		else if (tmp->next == NULL)
		{
			tmp->next = new;
			return (1);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_create_lst(char **tab, t_lst **a)
{
	int		i;
	int		nb;
	t_lst	*next;

	i = 0;
	while (tab[i])
	{
		nb = ft_atol(tab[i]);
		next = ft_lstnext(nb);
		if (ft_lstadd_back2(a, next) == 0)
			return (0);
		i++;
	}
	return (1);
}
