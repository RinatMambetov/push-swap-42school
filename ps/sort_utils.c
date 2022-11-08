/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:18:54 by greita            #+#    #+#             */
/*   Updated: 2022/02/06 20:21:53 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_rbrrb(t_vars *vars)
{
	int	item;

	item = 0;
	while (item < vars->size_stack_b)
	{
		vars->rb[item] = item;
		vars->rrb[item] = vars->size_stack_b - item;
		item++;
	}
}

int	ft_getitem_a(t_vars *vars, int num_b, int item)
{
	int		delta;
	int		temp;
	int		num_a;
	int		item_a;
	t_list	*elem;

	delta = vars->size_stack_a + vars->size_stack_b;
	while (item < vars->size_stack_a)
	{
		elem = vars->stack_a;
		temp = item;
		while (temp--)
			elem = elem->next;
		num_a = *(int *)elem->content;
		if (num_a > num_b && (num_a - num_b) < delta)
		{
			delta = num_a - num_b;
			item_a = item;
		}
		item++;
	}
	return (item_a);
}

void	ft_get_rarra(t_vars *vars)
{
	int		item_a;
	int		item_b;
	int		item;
	int		num_b;
	t_list	*elem;

	item_b = 0;
	while (item_b < vars->size_stack_b)
	{
		item = item_b;
		elem = vars->stack_b;
		while (item--)
			elem = elem->next;
		num_b = *(int *)elem->content;
		item = 0;
		item_a = ft_getitem_a(vars, num_b, item);
		vars->ra[item_b] = item_a;
		vars->rra[item_b] = vars->size_stack_a - item_a;
		item_b++;
	}
}

void	ft_getscores(t_vars	*vars)
{
	int	i;

	i = 0;
	while (i < vars->size_stack_b)
	{
		vars->score[i] = vars->ra[i] + vars->rra[i];
		vars->score[i] += vars->rb[i] + vars->rrb[i];
		vars->score[i] += vars->rr[i] + vars->rrr[i];
		i++;
	}
}

int	ft_get_minscoreid(t_vars *vars)
{
	int	i;
	int	min_score;
	int	min_id;

	i = 0;
	min_score = vars->score[i];
	min_id = i;
	while (i < vars->size_stack_b)
	{
		if (min_score > vars->score[i])
		{
			min_score = vars->score[i];
			min_id = i;
		}
		i++;
	}
	return (min_id);
}
