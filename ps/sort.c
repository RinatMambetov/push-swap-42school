/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:32:49 by greita            #+#    #+#             */
/*   Updated: 2022/02/07 14:20:01 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_takeopers_r(t_vars *vars, int id)
{
	while (vars->ra[id] || vars->rb[id] || vars->rr[id])
	{
		if (vars->ra[id])
		{
			ft_rotate(&vars->stack_a, 'a', 1);
			vars->ra[id]--;
		}
		if (vars->rb[id])
		{
			ft_rotate(&vars->stack_b, 'b', 1);
			vars->rb[id]--;
		}
		if (vars->rr[id])
		{
			ft_rotate_all(vars, 1);
			vars->rr[id]--;
		}
	}
}

void	ft_takeopers_rr(t_vars *vars, int id)
{
	while (vars->rra[id] || vars->rrb[id] || vars->rrr[id])
	{
		if (vars->rra[id])
		{
			ft_reverse_rotate(&vars->stack_a, 'a', 1);
			vars->rra[id]--;
		}
		if (vars->rrb[id])
		{
			ft_reverse_rotate(&vars->stack_b, 'b', 1);
			vars->rrb[id]--;
		}
		if (vars->rrr[id])
		{
			ft_reverse_rotate_all(vars, 1);
			vars->rrr[id]--;
		}
	}
}

int	ft_getminid_stacka(t_vars *vars)
{
	int		item;
	int		minid;
	int		min;
	t_list	*temp;

	item = 0;
	minid = 0;
	min = vars->size_stack_a;
	temp = vars->stack_a;
	while (item < vars->size_stack_a)
	{
		if (*(int *)temp->content < min)
		{
			minid = item;
			min = *(int *)temp->content;
		}
		temp = temp->next;
		item++;
	}
	return (minid);
}

void	ft_upminid_stacka(t_vars *vars)
{
	int	ra;
	int	rra;
	int	minid;

	minid = ft_getminid_stacka(vars);
	ra = minid;
	rra = vars->size_stack_a - minid;
	if (ra <= rra)
		while (ra--)
			ft_rotate(&vars->stack_a, 'a', 1);
	else
		while (rra--)
			ft_reverse_rotate(&vars->stack_a, 'a', 1);
}

void	ft_sort(t_vars *vars)
{
	int	i;
	int	size_stack_b;
	int	minscoreid;

	i = 0;
	ft_fillstack_b(vars);
	size_stack_b = vars->size_stack_b;
	ft_sort_three(&vars->stack_a);
	while (i < size_stack_b)
	{
		ft_get_rbrrb(vars);
		ft_get_rarra(vars);
		ft_checkopers(vars);
		ft_optimizeopers(vars);
		ft_getscores(vars);
		minscoreid = ft_get_minscoreid(vars);
		ft_takeopers_r(vars, minscoreid);
		ft_takeopers_rr(vars, minscoreid);
		ft_push(&vars->stack_b, &vars->stack_a, 'a', 1);
		vars->size_stack_a++;
		vars->size_stack_b--;
		i++;
	}
	ft_upminid_stacka(vars);
}
