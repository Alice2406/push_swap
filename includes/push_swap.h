/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:41:11 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/23 15:42:31 by aniezgod         ###   ########.fr       */
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
int		ft_error(void);
int		ft_check_int(char **str);
char	*arg_join(char **argv);
t_lst	*ft_lstnext(int content);
int		ft_create_lst(char **tab, t_lst **a);
int		ft_lstsize_ps(t_lst *lst);
void	ft_swap_a(t_lst **a);
void	ft_swap_b(t_lst **b);
void	ft_swap_a_and_b(t_lst **a, t_lst **b);
void	ft_lstadd_front2(t_lst **lst, int nb);
void	ft_push_b(t_lst **a, t_lst **b);
void	ft_push_a(t_lst **a, t_lst **b);
void	ft_lst_del_first(t_lst **lst);
void	ft_print_lst(t_lst **a);
t_lst	*ft_lstnew2(int nb);
void	ft_rotate_a(t_lst **a);
void	ft_reverse_rotate_a(t_lst **a);
void	ft_lst_del_last(t_lst **lst);
void	ft_rotate_b(t_lst **b);
void	ft_rotate_a_and_b(t_lst **a, t_lst **b);
t_lst	*ft_lstlast2(t_lst *lst);
void	ft_reverse_rotate_b(t_lst **b);
void	ft_reverse_rotate_a_and_b(t_lst **a, t_lst **b);
void	ft_algo(t_lst **a, t_lst **b);
int		ft_check_lst(t_lst *a);
void	ft_few_arguments(t_lst **a);
int	ft_moyenne(t_lst *a);
t_lst	*ft_lst_before_last(t_lst *lst);
int	ft_mediane(t_lst *a);

#endif