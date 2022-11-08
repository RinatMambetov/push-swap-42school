/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:59:30 by greita            #+#    #+#             */
/*   Updated: 2022/02/08 11:43:04 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char c, int print)
{
	t_list	*temp;

	if (ft_lstsize(*stack) > 1)
	{
		temp = *stack;
		*stack = (*stack)->next;
		ft_lstadd_back(stack, temp);
		if (print)
		{
			if (c == 'a')
				write(1, "ra\n", 3);
			else if (c == 'b')
				write(1, "rb\n", 3);
		}
	}
}

void	ft_rotate_all(t_vars *vars, int print)
{
	ft_rotate(&vars->stack_a, 'a', 0);
	ft_rotate(&vars->stack_b, 'b', 0);
	if (print)
		write(1, "rr\n", 3);
}

t_list	*ft_lstsecondlast(t_list *lst)
{
	while (lst)
	{
		if (lst -> next -> next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}

void	ft_reverse_rotate(t_list **stack, char c, int print)
{
	t_list	*temp;
	t_list	*last;
	t_list	*secondlast;

	if (ft_lstsize(*stack) > 1)
	{
		last = ft_lstlast(*stack);
		secondlast = ft_lstsecondlast(*stack);
		temp = *stack;
		*stack = last;
		(*stack)->next = temp;
		secondlast->next = NULL;
		if (print)
		{
			if (c == 'a')
				write(1, "rra\n", 4);
			else if (c == 'b')
				write(1, "rrb\n", 4);
		}
	}
}

void	ft_reverse_rotate_all(t_vars *vars, int print)
{
	ft_reverse_rotate(&vars->stack_a, 'a', 0);
	ft_reverse_rotate(&vars->stack_b, 'b', 0);
	if (print)
		write(1, "rrr\n", 4);
}
