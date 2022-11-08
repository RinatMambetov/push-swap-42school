/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:52:42 by greita            #+#    #+#             */
/*   Updated: 2022/02/08 10:48:32 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_takepush(t_vars *vars, char *line)
{
	if (!ft_strncmp(line, "pa\n", ft_strlen((const char *)line)))
	{
		ft_push(&vars->stack_b, &vars->stack_a, 'a', 0);
		vars->size_stack_b--;
		vars->size_stack_a++;
		return (1);
	}
	else if (!ft_strncmp(line, "pb\n", ft_strlen((const char *)line)))
	{
		ft_push(&vars->stack_a, &vars->stack_b, 'b', 0);
		vars->size_stack_a--;
		vars->size_stack_b++;
		return (1);
	}
	else
		return (0);
}

void	ft_takeopers(t_vars *vars, char *line)
{
	if (!ft_takepush(vars, line))
	{
		if (!ft_strncmp(line, "sa\n", ft_strlen((const char *)line)))
			ft_swap(&vars->stack_a, 'a', 0);
		else if (!ft_strncmp(line, "sb\n", ft_strlen((const char *)line)))
			ft_swap(&vars->stack_b, 'b', 0);
		else if (!ft_strncmp(line, "ss\n", ft_strlen((const char *)line)))
			ft_swap_all(vars, 0);
		else if (!ft_strncmp(line, "ra\n", ft_strlen((const char *)line)))
			ft_rotate(&vars->stack_a, 'a', 0);
		else if (!ft_strncmp(line, "rb\n", ft_strlen((const char *)line)))
			ft_rotate(&vars->stack_b, 'b', 0);
		else if (!ft_strncmp(line, "rr\n", ft_strlen((const char *)line)))
			ft_rotate_all(vars, 0);
		else if (!ft_strncmp(line, "rra\n", ft_strlen((const char *)line)))
			ft_reverse_rotate(&vars->stack_a, 'a', 0);
		else if (!ft_strncmp(line, "rrb\n", ft_strlen((const char *)line)))
			ft_reverse_rotate(&vars->stack_b, 'b', 0);
		else if (!ft_strncmp(line, "rrr\n", ft_strlen((const char *)line)))
			ft_reverse_rotate_all(vars, 0);
		else
			ft_error();
	}
}

void	ft_checksort(t_vars *vars)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = vars->stack_a;
	if (vars->size_stack_b)
	{
		write(1, "KO\n", 3);
		exit(EXIT_SUCCESS);
	}
	while (i < vars->size_stack_a - 1)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
		{
			write(1, "KO\n", 3);
			exit(EXIT_SUCCESS);
		}
		temp = temp->next;
		i++;
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_vars	vars;

	vars.stack_a = NULL;
	vars.stack_b = NULL;
	if (argc > 1)
	{
		vars.args = ft_getargs(argc, argv);
		vars.sorted_args = ft_getsorted_args(vars.args);
		vars.indexes = ft_getindexes(vars.args, vars.sorted_args);
		ft_fillstack_a(&vars, vars.indexes, vars.args[0]);
		ft_vars_init(&vars);
		line = ft_get_nextline(0);
		while (line)
		{
			ft_takeopers(&vars, line);
			free(line);
			line = ft_get_nextline(0);
		}
		free(line);
		ft_checksort(&vars);
		ft_freevars(&vars);
	}
	return (0);
}
