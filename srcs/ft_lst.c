/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:18:05 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/10 17:52:53 by aniezgod         ###   ########.fr       */
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

void	ft_lstadd_back2(t_lst **a, t_lst *new)
{
	t_lst	*last_element;

	last_element = ft_lstlast2(*a);
	if (last_element == NULL)
		last_element = new;
	last_element->next = new;
}

void    ft_create_lst(char **tab, t_lst **a)
{
    int i;
    int nb;
    t_lst  *next;

    i = 0;
    while (tab[i])
    {
        nb = ft_atol(tab[i]);
        next = ft_lstnext(nb);
        ft_lstadd_back2(a, next);
        i++;
    }
}