/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsorted_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:45:09 by greita            #+#    #+#             */
/*   Updated: 2022/02/08 11:19:28 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_leftrigth(long *arr, int *left, int *right)
{
	long	temp;

	if (*left <= *right)
	{
		temp = arr[*left];
		arr[*left] = arr[*right];
		(*left)++;
		arr[*right] = temp;
		(*right)--;
	}
}

long	*ft_quicksort(long *arr, int first, int last)
{
	int		left;
	int		right;
	long	middle;

	if (first < last)
	{
		left = first;
		right = last;
		middle = arr[(left + right) / 2];
		while (left <= right)
		{
			while (arr[left] < middle)
				left++;
			while (arr[right] > middle)
				right--;
			ft_swap_leftrigth(arr, &left, &right);
		}
		ft_quicksort(arr, first, right);
		ft_quicksort(arr, left, last);
	}
	return (arr);
}

long	*ft_getsorted_args(long *args)
{
	long	*sorted_args;
	int		i;

	i = 0;
	sorted_args = malloc(sizeof(long) * args[0]);
	if (!sorted_args)
		exit(EXIT_FAILURE);
	while (i < args[0])
	{
		sorted_args[i] = args[i + 1];
		i++;
	}
	sorted_args = ft_quicksort(sorted_args, 0, args[0] - 1);
	if (ft_checkargs_dup(sorted_args, args[0]))
		ft_error();
	return (sorted_args);
}

int	*ft_getindexes(long *args, long *sorted_args)
{
	int	*indexes;
	int	i;
	int	j;

	i = 1;
	indexes = malloc(sizeof(int) * args[0]);
	while (i < args[0] + 1)
	{
		j = 0;
		while (j < args[0])
		{
			if (args[i] == sorted_args[j])
				indexes[i - 1] = j;
			j++;
		}
		i++;
	}
	return (indexes);
}
