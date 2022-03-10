/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:27:36 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/10 17:54:16 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(void)
{
    ft_printf("Error\n");
}

int main(int argc, char **argv)
{
    char **tab2;
    int i;
    t_lst   *a;
 //   t_lst   *b;
    
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
            ft_printf("%s\n", arg_join(argv));
            ft_create_lst(tab2, &a);
        }
    }
}