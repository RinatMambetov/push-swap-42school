/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort345.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:04:41 by greita            #+#    #+#             */
/*   Updated: 2022/02/07 14:20:47 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **stack)
{
	int	num_first;
	int	num_second;
	int	num_third;

	num_first = *(int *)(*stack)->content;
	num_second = *(int *)(*stack)->next->content;
	num_third = *(int *)(*stack)->next->next->content;
	if (num_first < num_third && num_third < num_second)
	{
		ft_swap(stack, 'a', 1);
		ft_rotate(stack, 'a', 1);
	}
	else if (num_second < num_third && num_third < num_first)
		ft_rotate(stack, 'a', 1);
	else if (num_third < num_second && num_second < num_first)
	{
		ft_swap(stack, 'a', 1);
		ft_reverse_rotate(stack, 'a', 1);
	}
	else if (num_second < num_first && num_first < num_third)
		ft_swap(stack, 'a', 1);
	else if (num_third < num_first && num_first < num_second)
		ft_reverse_rotate(stack, 'a', 1);
}

void	ft_push_minid(t_vars *vars)
{
	ft_upminid_stacka(vars);
	ft_push(&vars->stack_a, &vars->stack_b, 'b', 1);
	vars->size_stack_a--;
	vars->size_stack_b++;
}

void	ft_sort_four(t_vars *vars)
{
	ft_push_minid(vars);
	ft_sort_three(&vars->stack_a);
	ft_push(&vars->stack_b, &vars->stack_a, 'a', 1);
	vars->size_stack_a++;
	vars->size_stack_b--;
}

void	ft_sort_five(t_vars *vars)
{
	ft_push_minid(vars);
	ft_sort_four(vars);
	ft_push(&vars->stack_b, &vars->stack_a, 'a', 1);
	vars->size_stack_a++;
	vars->size_stack_b--;
}
