/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:41:11 by aniezgod          #+#    #+#             */
/*   Updated: 2022/06/02 19:16:44 by aniezgod         ###   ########.fr       */
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

/*
**	TO DELETE
*/

void	ft_print_lst(t_lst **a);

/*
**	MAIN 2
*/

int		split_main(t_lst **a, t_lst **b, char *arg_ptr);

/*
**	LISTES
*/

t_lst	*ft_lstnext(int content);
t_lst	*ft_lstlast2(t_lst *lst);
t_lst	*ft_lst_before_last(t_lst *lst);
t_lst	*ft_lstnew2(int nb);
int		ft_lstsize_ps(t_lst *lst);
int		ft_lstadd_back2(t_lst **lst, t_lst *new);
int		ft_create_lst(char **tab, t_lst **a);
void	ft_lstadd_front2(t_lst **lst, int nb);
void	ft_lst_del_first(t_lst **lst);
void	ft_lst_del_last(t_lst **lst);
void	lst_clear(t_lst **lst);

/*
**	CHECK ET ERROR
*/

int		ft_check(char *str);
int		ft_check_int(char **str);
int		ft_check_lst(t_lst *a);
int		ft_error(void);
char	*arg_join(char **argv);
void	strsfree(char **strs);

/*
**	OPERATIONS
*/

void	ft_swap_a(t_lst **a);
void	ft_push_a(t_lst **a, t_lst **b);
void	ft_rotate_a(t_lst **a);
void	ft_reverse_rotate_a(t_lst **a);
void	ft_swap_b(t_lst **b);
void	ft_push_b(t_lst **a, t_lst **b);
void	ft_rotate_b(t_lst **b);
void	ft_reverse_rotate_b(t_lst **b);
void	ft_swap_a_and_b(t_lst **a, t_lst **b);
void	ft_rotate_a_and_b(t_lst **a, t_lst **b);
void	ft_reverse_rotate_a_and_b(t_lst **a, t_lst **b);

/*
**	ALGO FEW NB
*/

int		ft_place(t_lst *a, int b);
void	ft_insertion_first(t_lst **a, t_lst **b);
void	ft_insertion_second(t_lst **a, t_lst **b);
void	ft_three_nb(t_lst **a);
void	ft_algo_for_5(t_lst **a, t_lst **b);
void	ft_which_sorting(t_lst **a, t_lst **b);
/*
**	ALGO 
*/

void	ft_first_part(t_lst **a, t_lst **b, int med_sup);
void	ft_tri_part(t_lst **a, t_lst **b);
void	ft_algo(t_lst **a, t_lst **b);
void	ft_between_part(t_lst **a, t_lst **b, int med_sup, int med_inf);
void	ft_finish_part(t_lst **a, t_lst **b, int med_sup);
void	ft_tri_part2(t_lst **a, t_lst **b);
void	ft_b_push(int nb, t_lst **b);
int		ft_find_biggest(t_lst *b);
int		ft_find_smallest(t_lst *b);
int		ft_find_place(t_lst *b, int nb);
int		ft_rrb_or_rb(t_lst *b, int nb);
int		ft_compare_place(int smallest, int biggest, t_lst *b);
int		ft_median(t_lst *a);
int		half_median_sup(t_lst *a, int median);
int		half_median_inf(t_lst *a, int median);

#endif