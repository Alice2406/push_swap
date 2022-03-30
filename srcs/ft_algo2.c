/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:57:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/30 02:43:56 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_compare_lst_tab(t_lst **a, t_lst **b, int *tab, int length)
{
	int	i;
	int size;

	//i = 1;
	size = ft_lstsize_ps(*a);
	ft_printf("size = %d\n", size);
	for(int i = 1; i < length + 1; i++)
		printf("tab[%d] = %d\n",i, tab[i]);
	i = 1;
	while (size > 0)
	{
		if (size == 1 && tab[i] == (*a)->nb)
			ft_printf("i'm the boss\n");
		ft_printf("tab[%d]= %d\n", i, tab[i]);
		if (tab[i] == (*a)->nb && i < length + 1)
		{
			i++;
			ft_rotate_a(a);
		}
		else
			ft_push_b(a, b);
		size--;
	}
	ft_printf("a\n");
	ft_print_lst(a);
	ft_printf("\nb\n");
	ft_print_lst(b);
}

void	ft_algo(t_lst **a, t_lst **b)
{
	int length_plssc;
	int *tab;
	int *plssc;
	int	*new_tab;
	int size;
	t_lst *tmp;
	
	tmp = *b;
	size = ft_lstsize_ps(*a);
	tab = ft_lst_to_tab(*a, size);
	length_plssc = ft_length_plssc(tab, size, &new_tab);
	// for(int i = 0; i < size; i++)
	// 	printf("new_tab = %d\n", new_tab[i]);
	plssc = ft_tab_plssc(tab, length_plssc, new_tab);
	// ft_printf("plssc = %d\n", length_plssc);
	// for(int i = 1; i < length_plssc + 1; i++)
	// 	printf("plssc[%d] = %d\n",i, plssc[i]);
	ft_compare_lst_tab(a, b, plssc, length_plssc);
}