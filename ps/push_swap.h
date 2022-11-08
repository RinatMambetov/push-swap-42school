/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:34:29 by greita            #+#    #+#             */
/*   Updated: 2022/02/08 11:59:22 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_vars
{
	long	*args;
	long	*sorted_args;
	int		*indexes;
	t_list	*stack_a;
	t_list	*stack_b;
	int		*ra;
	int		*rra;
	int		*rb;
	int		*rrb;
	int		*rr;
	int		*rrr;
	int		*score;
	int		size_stack_a;
	int		size_stack_b;
}	t_vars;

/*checkers.c*/
int		ft_checkargs_digit(char **args);
int		ft_checkargs_maxmin(long *args);
int		ft_issorted_args(long *args);
int		ft_checkargs_dup(long *sorted_args, long size);
int		ft_checkargs_empty(int argc, char **argv);
/*getargs.c*/
long	*ft_getargs(int argc, char **argv);
void	ft_error(void);
/*getsortedargs.c*/
long	*ft_getsorted_args(long *args);
int		*ft_getindexes(long *args, long *sorted_args);
/*opers.c*/
void	ft_swap(t_list **stack, char c, int print);
void	ft_swap_all(t_vars *vars, int print);
void	ft_push(t_list **stack_out, t_list **stack_in, char c, int print);
void	ft_checkopers(t_vars *vars);
void	ft_optimizeopers(t_vars *vars);
/*operrr.c*/
void	ft_rotate(t_list **stack, char c, int print);
void	ft_rotate_all(t_vars *vars, int print);
void	ft_reverse_rotate(t_list **stack, char c, int print);
void	ft_reverse_rotate_all(t_vars *vars, int print);
/*sort345.c*/
void	ft_sort_three(t_list **stack);
void	ft_sort_four(t_vars *vars);
void	ft_sort_five(t_vars *vars);
/*sort_utils.c*/
void	ft_get_rbrrb(t_vars *vars);
void	ft_get_rarra(t_vars *vars);
void	ft_getscores(t_vars	*vars);
int		ft_get_minscoreid(t_vars *vars);
/*ps_utils.c*/
void	ft_fillstack_a(t_vars *vars, int *indexes, int size);
void	ft_fillstack_b(t_vars *vars);
void	ft_freevars(t_vars *vars);
void	ft_vars_init(t_vars *vars);
/*sort.c*/
void	ft_sort(t_vars *vars);
void	ft_upminid_stacka(t_vars *vars);

#endif
