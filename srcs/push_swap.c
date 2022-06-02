/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:27:36 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/02 19:32:21 by aniezgod         ###   ########.fr       */
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

void	strsfree(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

void	lst_clear(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*tmp_to_free;

	tmp_to_free = NULL;
	tmp = (*lst);
	while (tmp)
	{
		tmp_to_free = tmp;
		tmp = tmp->next;
		free(tmp_to_free);
	}
}

int	split_main(t_lst **a, t_lst **b, char *arg_ptr)
{
	char	**tab;

	tab = ft_split(arg_ptr, ' ');
	if (ft_check_int(tab) == 0)
		ft_error();
	else
	{
		if (ft_create_lst(tab, a) == 0)
		{
			strsfree(tab);
			return (1);
		}
		else if (ft_check_lst(*a) == 0)
			ft_which_sorting(a, b);
	}
	strsfree(tab);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*arg_ptr;
	t_lst	*a;
	t_lst	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (1);
	arg_ptr = arg_join(argv);
	if (ft_check(arg_ptr) == 0)
		ft_error();
	else
		split_main(&a, &b, arg_ptr);
	free(arg_ptr);
	lst_clear(&a);
	lst_clear(&b);
}
