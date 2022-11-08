/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:22:41 by greita            #+#    #+#             */
/*   Updated: 2022/03/13 15:23:25 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fillstack_a(t_vars *vars, int *indexes, int size)
{
	int		i;
	t_list	*elem;

	i = 0;
	while (i < size)
	{
		elem = ft_lstnew(&indexes[i]);
		ft_lstadd_back(&vars->stack_a, elem);
		i++;
	}
}

void	ft_fillstack_b(t_vars *vars)
{
	int	i;
	int	min;
	int	max;
	int	mid;
	int	num;

	i = vars->size_stack_a;
	min = 0;
	max = vars->size_stack_a - 1;
	mid = (vars->size_stack_a - 1) / 2;
	while (i--)
	{
		num = *(int *)vars->stack_a->content;
		if (num == min || num == max || num == mid)
			ft_rotate(&vars->stack_a, 'a', 1);
		else
		{
			ft_push(&vars->stack_a, &vars->stack_b, 'b', 1);
			vars->size_stack_a--;
			vars->size_stack_b++;
		}
	}
}

void	ft_lstclear_ps(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst && !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
}

void	ft_freevars(t_vars *vars)
{
	free(vars->args);
	free(vars->sorted_args);
	free(vars->indexes);
	ft_lstclear_ps(&vars->stack_a, &free);
	ft_lstclear_ps(&vars->stack_b, &free);
	free(vars->rb);
	free(vars->rrb);
	free(vars->ra);
	free(vars->rra);
	free(vars->rr);
	free(vars->rrr);
	free(vars->score);
}

void	ft_vars_init(t_vars *vars)
{
	vars->size_stack_a = ft_lstsize(vars->stack_a);
	vars->size_stack_b = ft_lstsize(vars->stack_b);
	vars->ra = malloc(sizeof(int) * vars->size_stack_a);
	vars->rra = malloc(sizeof(int) * vars->size_stack_a);
	vars->rb = malloc(sizeof(int) * vars->size_stack_a);
	vars->rrb = malloc(sizeof(int) * vars->size_stack_a);
	vars->rr = malloc(sizeof(int) * vars->size_stack_a);
	vars->rrr = malloc(sizeof(int) * vars->size_stack_a);
	vars->score = malloc(sizeof(int) * vars->size_stack_a);
	if (!vars->ra || !vars->rra || !vars->rb || !vars->rrb)
		exit(EXIT_FAILURE);
	if (!vars->score || !vars->rr || !vars->rrr)
		exit(EXIT_FAILURE);
}
