/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:03:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/23 15:59:25 by aniezgod         ###   ########.fr       */
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

int	ft_mediane(t_lst *a)
{
	int n;
	int max;
	char *str;
	t_lst	*tmp;
	
	if (ft_lstsize_ps(a) % 2 == 0)
		max = ft_lstsize_ps(a) / 2;
	else
		max = (ft_lstsize_ps(a) + 1) / 2;
	str = malloc(sizeof(char) * max + 1);
	str[max + 1] = '\0';
	n = 0;
	while (n <= max)
	{
		
		str[n] = a->nb;
		tmp = a;	
		while (tmp)
		{
			if ((tmp->nb >= str[n] && tmp->nb < str[n - 1]) 
				|| (n == 0 && tmp->nb >= str[n]))
				tmp = tmp->next;
			if (tmp->next == NULL)
			{
				ft_printf("str[n] = %d\n", str[n]);
				n++;
				break;
			}
			else
			{
				str[n] = tmp->next->nb;
				ft_printf("str[n] = %d\n", str[n]);
				n++;
				break;
			}
		}
	}
	ft_printf("str = %s\n", str);
	return (0);
}

// int	ft_mediane(t_lst *a)
// {
// 	int	n;
// 	int size;
	
// 	size = ft_lstsize_ps(a);
// 	n = 0;
// 	while (a)
// 	{
// 		n += a->nb;
// 		a = a->next;
// 	}
// 	n = n / size;
// 	return (n);
// }

// void	ft_algo(t_lst **a, t_lst **b)
// {
// 	int n;
// 	int moy;
// 	int nb_ope;
	
// 	nb_ope = 0;
// 	moy = ft_mediane(*a);
// 	ft_printf("mediane = %d\n", moy);
// 	if ((*a)->nb < moy)
// 	{
// 		ft_rotate_a(a);
// 		nb_ope++;
// 	}
// 	else
// 	{
// 		ft_push_b(a, b);
// 		nb_ope++;
// 	}
// 	ft_print_lst(a);
// 	n = ft_lstsize_ps(*a) - 1;
// 	while (n != 0)
// 	{
// 		if ((*a)->nb > ft_lstlast2(*a)->nb && (*a)->next->nb < (*a)->nb && (*a)->next->nb > ft_lstlast2(*a)->nb)
// 		{
// 			ft_swap_a(a);
// 			ft_rotate_a(a);
// 			ft_rotate_a(a);
// 			nb_ope = nb_ope + 2;
// 		}
// 		else if ((*a)->nb > ft_lstlast2(*a)->nb)
// 		{
// 			ft_rotate_a(a);
// 			nb_ope++;
// 		}
// 		else if ((*a)->next->nb < (*a)->nb && (*a)->next->nb > ft_lst_before_last(*a)->nb)
// 		{
// 			ft_reverse_rotate_a(a);
// 			ft_swap_a(a);
// 			ft_rotate_a(a);
// 			ft_rotate_a(a);
// 			nb_ope = nb_ope + 4;
// 		}
// 		else
// 		{
// 			ft_push_b(a, b);
// 			nb_ope++;
// 		}
// 		n--;
// 	}
// 	ft_printf("nombre operations = %d\n", nb_ope);
// }