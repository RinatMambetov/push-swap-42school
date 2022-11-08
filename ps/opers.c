/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:02:42 by greita            #+#    #+#             */
/*   Updated: 2022/02/07 16:06:14 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char c, int print)
{
	t_list	*temp;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
		if (print)
		{
			if (c == 'a')
				write(1, "sa\n", 3);
			else if (c == 'b')
				write(1, "sb\n", 3);
		}
	}
}

void	ft_swap_all(t_vars *vars, int print)
{
	ft_swap(&vars->stack_a, 'a', 0);
	ft_swap(&vars->stack_b, 'b', 0);
	if (print)
		write(1, "ss\n", 3);
}

void	ft_push(t_list **stack_out, t_list **stack_in, char c, int print)
{
	t_list	*temp;

	if (*stack_out)
	{
		temp = *stack_out;
		*stack_out = (*stack_out)->next;
		temp->next = *stack_in;
		*stack_in = temp;
		if (print)
		{
			if (c == 'a')
				write(1, "pa\n", 3);
			else if (c == 'b')
				write(1, "pb\n", 3);
		}
	}
}

void	ft_checkopers(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->size_stack_b)
	{
		if (!vars->ra[i])
			vars->rra[i] = 0;
		if (!vars->rb[i])
			vars->rrb[i] = 0;
		if (vars->ra[i] && vars->rra[i])
		{
			if (vars->ra[i] > vars->rra[i])
				vars->ra[i] = 0;
			else
				vars->rra[i] = 0;
		}
		if (vars->rb[i] && vars->rrb[i])
		{
			if (vars->rb[i] > vars->rrb[i])
				vars->rb[i] = 0;
			else
				vars->rrb[i] = 0;
		}
		i++;
	}
}

void	ft_optimizeopers(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->size_stack_b)
	{
		vars->rr[i] = 0;
		vars->rrr[i] = 0;
		while (vars->ra[i] && vars->rb[i])
		{
			vars->rr[i]++;
			vars->ra[i]--;
			vars->rb[i]--;
		}
		while (vars->rra[i] && vars->rrb[i])
		{
			vars->rrr[i]++;
			vars->rra[i]--;
			vars->rrb[i]--;
		}
		i++;
	}
}
