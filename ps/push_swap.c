/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:34:50 by greita            #+#    #+#             */
/*   Updated: 2022/02/08 10:48:24 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choosesort(t_vars *vars)
{
	if (vars->args[0] == 2)
		ft_swap(&vars->stack_a, 'a', 1);
	else if (vars->args[0] == 3)
		ft_sort_three(&vars->stack_a);
	else if (vars->args[0] == 4)
		ft_sort_four(vars);
	else if (vars->args[0] == 5)
		ft_sort_five(vars);
	else
		ft_sort(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.stack_a = NULL;
	vars.stack_b = NULL;
	if (argc > 1)
	{
		vars.args = ft_getargs(argc, argv);
		if (ft_issorted_args(vars.args))
			exit(EXIT_SUCCESS);
		vars.sorted_args = ft_getsorted_args(vars.args);
		vars.indexes = ft_getindexes(vars.args, vars.sorted_args);
		ft_fillstack_a(&vars, vars.indexes, vars.args[0]);
		ft_vars_init(&vars);
		ft_choosesort(&vars);
		ft_freevars(&vars);
	}
	return (0);
}
