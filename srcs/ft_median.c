/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:35:35 by aniezgod          #+#    #+#             */
/*   Updated: 2022/05/18 22:21:47 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(t_lst *a)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		left;
	int		right;

	tmp = a;
	while (1)
	{
		left = 0;
		right = 0;
		tmp2 = a;
		while (tmp2)
		{
			if (tmp->nb > tmp2->nb)
				left++;
			else if (tmp->nb < tmp2->nb)
				right++;
			tmp2 = tmp2->next;
		}
		if (left == right || left + 1 == right || left == right + 1)
			return (tmp->nb);
		else
			tmp = tmp->next;
	}
	return (0);
}

int	half_median_sup(t_lst *a, int median)
{
	t_lst	*tmp;
	t_lst	*median_sup;
	t_lst	*tmp2;
	int		med_sup;

	tmp = a;
	median_sup = ft_lstnew2(median);
	while (tmp)
	{
		if (tmp->nb < median)
		{
			tmp2 = ft_lstnext(tmp->nb);
			ft_lstadd_back2(&median_sup, tmp2);
		}
		tmp = tmp->next;
	}
	ft_lst_del_first(&median_sup);
	med_sup = ft_median(median_sup);
	lst_clear(&median_sup);
	return (med_sup);
}

int	half_median_inf(t_lst *a, int median)
{
	t_lst	*tmp;
	t_lst	*median_inf;
	t_lst	*tmp2;
	int		med_inf;

	tmp = a;
	median_inf = ft_lstnew2(median);
	while (tmp)
	{
		if (tmp->nb > median)
		{
			tmp2 = ft_lstnext(tmp->nb);
			ft_lstadd_back2(&median_inf, tmp2);
		}
		tmp = tmp->next;
	}
	ft_lst_del_first(&median_inf);
	med_inf = ft_median(median_inf);
	lst_clear(&median_inf);
	return (med_inf);
}
