/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:57:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/04/01 14:38:06 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
_print_list(t_lst **a,t_lst **b)
{
	ft_printf("\nLIST A\n");
	ft_print_lst(a);
	ft_printf("\nLIST B\n");
	ft_print_lst(b);
	ft_printf("\n\n");
}

void	ft_compare_lst_tab(t_lst **a, t_lst **b, int *tab, int length)
{
	int	i;
	int size;

	size = ft_lstsize_ps(*a);
	i = 1;
	while (size > 0)
	{
		if ((i == 2 && (*a)->nb < ft_lstlast2(*a)->nb) 
			|| (i > 2 && (*a)->nb < ft_lstlast2(*a)->nb 
			&& (*a)->nb > ft_lst_before_last(*a)->nb))
		{
			ft_reverse_rotate_a(a);
			ft_swap_a(a);
			ft_rotate_a(a);
			ft_rotate_a(a);
		}
		else if (tab[i] == (*a)->nb && i < length + 1)
		{
			i++;
			ft_rotate_a(a);
		}
		else
			ft_push_b(a, b);
		size--;
	}
}
int	ft_lst_half_size(t_lst *a)
{
	int i;

	i = ft_lstsize_ps(a);
	if (i % 2 == 0)
		i = i / 2;
	else
		i = (i + 1) / 2;
	return (i);
}

int ft_place_a(t_lst *a, int b)
{
	int i;
	int size;
	
	size = ft_lstsize_ps(a);
	i = 0;
	while (size > 0 && b > a->nb)
	{
		i++;
		a = a->next;
		size--;
	}
	return (i);
}

void	ft_insertion(t_lst **a,t_lst **b)
{
	int place;
	int reverse;
	int half_size;
	int size;

	size = ft_lstsize_ps(*a);
	while (*b)
	{
		half_size = ft_lst_half_size(*a);
		place = ft_place_a(*a, (*b)->nb);
		// ft_printf("place = %d - nnb = %d\n", place, (*b)->nb);
		//_print_list(a, b);
		reverse = place;
		if (place == 0)
			ft_push_a(a, b);
		else if (place <= half_size)
		{
			while (place > 0)
			{
				ft_rotate_a(a);
				place--;
			}
			ft_push_a(a, b);
			while (reverse > 0)
			{
				ft_reverse_rotate_a(a);
				reverse--;
			}
		}
		else if (place > half_size)
		{
			place = size - place;
			reverse = place;
			// ft_printf("place = %d\n", place);
			while (place > 0)
			{
				ft_reverse_rotate_a(a);
				place--;
			}
			ft_push_a(a, b);
			while (reverse >= 0)
			{
				ft_rotate_a(a);
				reverse--;
			}
		}
		size++;
	}
}

void	ft_algo(t_lst **a, t_lst **b)
{
	int length_plssc;
	int *tab;
	int *plssc;
	int	*new_tab;
	int size;

	size = ft_lstsize_ps(*a);
	tab = ft_lst_to_tab(*a, size);
	length_plssc = ft_length_plssc(tab, size, &new_tab);
	plssc = ft_tab_plssc(tab, length_plssc, new_tab);
	ft_compare_lst_tab(a, b, plssc, length_plssc);
	ft_insertion(a, b);
}
	// for(int i = 0; i < size; i++)
	// 	printf("new_tab = %d\n", new_tab[i]);
	// ft_printf("plssc = %d\n", length_plssc);
	// for(int i = 1; i < length_plssc + 1; i++)
	// 	printf("plssc[%d] = %d\n",i, plssc[i]);