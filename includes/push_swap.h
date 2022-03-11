/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:41:11 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/11 14:38:34 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_lst
{
	int				nb;
	struct s_lst	*next;
}	t_lst;

int		ft_check(char *str);
void	ft_error(void);
int		ft_check_int(char **str);
char	*arg_join(char **argv);
t_lst	*ft_lstnext(int content);
void	ft_create_lst(char **tab, t_lst **a);

#endif