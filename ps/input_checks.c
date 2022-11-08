/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:21:22 by greita            #+#    #+#             */
/*   Updated: 2022/02/08 11:50:41 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkargs_digit(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && args[i][j] != '-' && args[i][j] != '+'
				&& !ft_isdigit(args[i][j]))
				return (1);
			if (j != 0 && !ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checkargs_maxmin(long *args)
{
	int	i;

	i = 1;
	while (i < args[0] + 1)
	{
		if (args[i] > INT_MAX || args[i] < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_issorted_args(long *args)
{
	int	i;

	i = 1;
	while (i < args[0])
	{
		if (args[i] >= args[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkargs_dup(long *sorted_args, long size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (sorted_args[i] == sorted_args[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkargs_empty(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strlen(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
