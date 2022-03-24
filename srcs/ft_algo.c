/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/24 00:53:46 by aniezgod         ###   ########.fr       */
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

int	*ft_lst_to_tab(t_lst *a, int size)
{
	int *tab;
	int	i;
	
	tab = malloc(sizeof(int) * size);
	i = 0;
	while(size != 0)
	{
		tab[i] = a->nb;
		i++;
		a = a->next;
		size--;
	}
	return (tab);
}

void	ft_algo(t_lst **a, t_lst **b)
{
	int	*tab;
	int *L;
	int	size;
	int i;
	int	j;
	int	max;
	int m;
	t_lst *tmp;

	tmp = *b;
	size = ft_lstsize_ps(*a);
	tab = ft_lst_to_tab(*a, size);
	L = malloc(sizeof(int) * size);
	i = 0;
	while (L[i])
	{
		L[i] = 1;
		i++;
	}
	i = 1;
	m = L[0];
	while (i < size - 1)
	{
		max = 0;
		j = 0;
		while (j < i - 1)
		{
			if (tab[i] <= tab[j] && L[j] > max)
				max = L[j];
			j++;
		}
		L[i] = max + 1;
		if (L[i] > m)
			m = L[i];
		i++;
	}
	ft_printf ("%d\n", m);
}



//int	ft_mediane(t_lst *a)
//{
//	t_lst *tmp;
//	t_lst *tmp2;
//	int nb_left;
//	int	nb_right;

//	tmp = a;
//	while(1)
//	{
//		nb_left = 0;
//		nb_right = 0;
//		tmp2 = a;
//		while(tmp2)
//		{
//			if (tmp->nb > tmp2->nb)
//				nb_left++;
//			else if	(tmp->nb < tmp2->nb)
//				nb_right++;
//			tmp2 = tmp2->next;
//		}
//		if (nb_left == nb_right || nb_left + 1 == nb_right || nb_left == nb_right + 1)
//			return (tmp->nb);
//		else
//			tmp = tmp->next;
//	}
//	return (0);
//}

//void	ft_algo(t_lst **a, t_lst **b)
//{
//	int n;
//	int med;
//	int nb_ope;
	
//	nb_ope = 0;
//	med = ft_mediane(*a);
//	ft_printf("la super mediane = %d\n", med);
//	while (1)
//	{
//		if ((*a)->nb < med)
//		{
//			ft_rotate_a(a);
//			nb_ope++;
//			break ;
//		}
//		else
//		{
//			ft_push_b(a, b);
//			nb_ope++;
//		}
//	}
//	n = ft_lstsize_ps(*a) - 1;
//	while (n != 0)
//	{
//		if ((*a)->nb > ft_lstlast2(*a)->nb && (*a)->next->nb < (*a)->nb && (*a)->next->nb > ft_lstlast2(*a)->nb)
//		{
//			ft_swap_a(a);
//			ft_rotate_a(a);
//			ft_rotate_a(a);
//			nb_ope = nb_ope + 2;
//		}
//		if (n == ft_lstsize_ps(*a) - 1 && (*a)->nb < ft_lstlast2(*a)->nb)
//		{
//			ft_reverse_rotate_a(a);
//			ft_swap_a(a);
//			ft_rotate_a(a);
//			ft_rotate_a(a);
//			nb_ope = nb_ope + 4;
//		}
//		else if ((*a)->nb > ft_lstlast2(*a)->nb)
//		{
//			ft_rotate_a(a);
//			nb_ope++;
//		}
//		else if (((*a)->next->nb < (*a)->nb && (*a)->next->nb > ft_lst_before_last(*a)->nb) && (n != ft_lstsize_ps(*a) - 1))
//		{
//			ft_reverse_rotate_a(a);
//			ft_swap_a(a);
//			ft_rotate_a(a);
//			ft_rotate_a(a);
//			nb_ope = nb_ope + 4;
//		}
//		else
//		{
//			ft_push_b(a, b);
//			nb_ope++;
//		}
//		n--;
//	}
//	ft_printf("nombre operations = %d\n", nb_ope);
//}