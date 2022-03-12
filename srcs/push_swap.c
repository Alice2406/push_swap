/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:27:36 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/12 22:04:05 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
}

void	ft_print_lst(t_lst **a)
{
	t_lst *tmp;
	tmp = *a;
	while(tmp)
	{
		if(!tmp->next)
		{
			ft_putnbr_fd((tmp->nb), 1);		
			return ;
		}
		else
		{
			ft_putnbr_fd((tmp->nb), 1);
			ft_printf(" ");
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
	int		i;
	t_lst	*a;
//	t_lst	*b;

	i = 0;
	if (argc < 2 || ft_check(arg_join(argv)) == 0)
	{
		ft_error();
		return (0);
	}
	else
	{
		tab2 = ft_split(arg_join(argv), ' ');
		if (ft_check_int(tab2) == 0)
		{
			ft_error();
			return (0);
		}
		else
		{
			if(ft_create_lst(tab2, &a) == 0)
				return (0);
			ft_printf("%d\n", ft_lstsize_ps(a));
			ft_print_lst(&a);
		}
	}
}
