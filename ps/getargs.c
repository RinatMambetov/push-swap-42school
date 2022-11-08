/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getargs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:42:00 by greita            #+#    #+#             */
/*   Updated: 2022/03/13 14:14:55 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

char	**ft_get_splitargs(int argc, char **argv)
{
	char	*args_str;
	char	*arg;
	char	**split_args;
	int		i;

	i = 1;
	args_str = ft_strdup(argv[i]);
	while (i < argc - 1)
	{
		arg = ft_strjoin(args_str, " ");
		free(args_str);
		args_str = ft_strjoin(arg, argv[i + 1]);
		free(arg);
		i++;
	}
	split_args = ft_split(args_str, ' ');
	free(args_str);
	return (split_args);
}

long	ft_atoi_pushswap(const char *str)
{
	int		neg;
	long	num;

	neg = 1;
	num = 0;
	if (*str == '-' || *str == '+' || *str == '0')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (neg * num);
}

long	*ft_get_argslong(char **split_args)
{
	int		i;
	long	count;
	long	*args_long;

	i = 1;
	count = 0;
	while (split_args[count])
		count++;
	args_long = malloc(sizeof(long) * (count + 1));
	if (!args_long)
		exit(EXIT_FAILURE);
	while (i < count + 1)
	{
		args_long[i] = ft_atoi_pushswap(split_args[i - 1]);
		free(split_args[i - 1]);
		i++;
	}
	args_long[0] = count;
	return (args_long);
}

long	*ft_getargs(int argc, char **argv)
{
	long	*args_long;
	char	**split_args;

	if (ft_checkargs_empty(argc, argv))
		ft_error();
	split_args = ft_get_splitargs(argc, argv);
	if (ft_checkargs_digit(split_args))
		ft_error();
	args_long = ft_get_argslong(split_args);
	if (ft_checkargs_maxmin(args_long))
		ft_error();
	free(split_args);
	return (args_long);
}
