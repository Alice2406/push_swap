/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:27:36 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/09 17:37:52 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(void)
{
    ft_printf("Error\n");
}

int ft_check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) || str[i] == ' ')
            i++;
        else if ((str[i] == '+' && ft_isdigit(str[i + 1])) 
            || (str[i] == '-' && ft_isdigit(str[i + 1])))
            i++;
        else
            return(0);
    }
    return (1);
}

char *arg_join(char **argv)
{
    char *tab_arg;
    int i;

    i = 2;
    if(argv[1])
        tab_arg = ft_strjoin(argv[1], " ");
    while(argv[i])
    {
        tab_arg = ft_strjoin(tab_arg, argv[i]);
        if (argv[i + 1] != NULL)
            tab_arg = ft_strjoin(tab_arg, " ");
        i++;
    }
    return (tab_arg);
}

int main(int argc, char **argv)
{
    char *tab_arg;
    if (argc < 2)
    {
        ft_error();
        return (0);
    }
    tab_arg = arg_join(argv);
    if (ft_check(tab_arg) == 0)
    {
        ft_error();
        return(0);
    }
    else
        ft_printf("%s\n", tab_arg);
}