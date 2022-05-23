/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:27:36 by aniezgod          #+#    #+#             */
/*   Updated: 2022/05/23 17:53:23 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_lst **a)
{
	t_lst	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (!tmp->next)
		{
			ft_putnbr_fd((tmp->nb), 1);
			ft_printf("\n");
			return ;
		}
		else
		{
			ft_putnbr_fd((tmp->nb), 1);
			ft_printf("\n");
			tmp = tmp->next;
		}
	}
}

int	ft_lstsize_ps(t_lst *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	char	**tab2;
	t_lst	*a;
	t_lst	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (1);
	if (ft_check(arg_join(argv)) == 0)
		ft_error();
	else
	{
		tab2 = ft_split(arg_join(argv), ' ');
		if (ft_check_int(tab2) == 0)
			ft_error();
		else
		{
			if (ft_create_lst(tab2, &a) == 0)
				return (0);
			if (ft_check_lst(a) == 1)
				return (1);
			else
				ft_which_sorting(&a, &b);
		}
	}
}
