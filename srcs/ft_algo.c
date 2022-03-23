/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/22 00:59:15 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_few_arguments(t_lst **a)
{
	if (ft_lstsize_ps(*a) == 2 && ft_check_lst(*a) == 0)
		ft_swap_a(a);
	else if (ft_lstsize_ps(*a) == 3)
	{
		if ((*a)->nb < (*a)->next->nb && (*a)->next->nb
			> (*a)->next->next->nb && (*a)->nb > (*a)->next->next->nb)
			ft_reverse_rotate_a(a);
		else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb
			< (*a)->next->next->nb && (*a)->nb > (*a)->next->next->nb)
			ft_rotate_a(a);
		else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb
			< (*a)->next->next->nb && (*a)->nb < (*a)->next->next->nb)
			ft_swap_a(a);
		else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb
			> (*a)->next->next->nb && (*a)->nb > (*a)->next->next->nb)
		{
			ft_swap_a(a);
			ft_reverse_rotate_a(a);
		}
		else
		{
			ft_reverse_rotate_a(a);
			ft_swap_a(a);
		}
	}
}

int	ft_moyenne(t_lst *a)
{
	int	n;
	int size;
	
	size = ft_lstsize_ps(a);
	n = 0;
	while (a)
	{
		n += a->nb;
		a = a->next;
	}
	n = n / size;
	return (n);
}

void	ft_algo(t_lst **a, t_lst **b)
{
	int n;
	int moy;
	int nb_ope;
	
	nb_ope = 0;
	moy = ft_moyenne(*a);
	ft_printf("moyenne = %d\n", moy);
	if ((*a)->nb < moy)
	{
		ft_rotate_a(a);
		nb_ope++;
	}
	else
	{
		ft_push_b(a, b);
		nb_ope++;
	}
	ft_print_lst(a);
	n = ft_lstsize_ps(*a) - 1;
	while (n != 0)
	{
		if ((*a)->nb > ft_lstlast2(*a)->nb && (*a)->next->nb < (*a)->nb && (*a)->next->nb > ft_lstlast2(*a)->nb)
		{
			ft_swap_a(a);
			ft_rotate_a(a);
			ft_rotate_a(a);
			nb_ope = nb_ope + 2;
		}
		else if ((*a)->nb > ft_lstlast2(*a)->nb)
		{
			ft_rotate_a(a);
			nb_ope++;
		}
		else if ((*a)->next->nb < (*a)->nb && (*a)->next->nb > ft_lst_before_last(*a)->nb)
		{
			ft_reverse_rotate_a(a);
			ft_swap_a(a);
			ft_rotate_a(a);
			ft_rotate_a(a);
			nb_ope = nb_ope + 4;
		}
		else
		{
			ft_push_b(a, b);
			nb_ope++;
		}
		n--;
	}
	ft_printf("nombre operations = %d\n", nb_ope);
}