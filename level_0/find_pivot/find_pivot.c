/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:51:34 by hyu               #+#    #+#             */
/*   Updated: 2020/02/03 18:41:10 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		sum_array(int *array, int n)
{
	int	i;
	int	sum;

	sum = 0;
	i = 1;
	while (i < n)
	{
		sum = sum + array[i];
		i++;
	}
	return (sum);
}
int		find_pivot(int *arr, int n)
{
	int right;
	int left;

	int i;

	i = 0;
	left = 0;
	right = sum_array(arr, n );
	i++;
	while (i < n)
	{
		left = left + arr[i - 1];
		right = right - arr[i];
		if (left == right)
			return (i);
		i++;
	}
	return (-1);
}


int		main(void)
{
	int	arr1[] = { 1 , 2 };
	int	n1 = 2;
	int	i;

	i  = find_pivot(arr1, n1);
	printf("%d", i);
	return (0);
}
