/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:59:34 by hyu               #+#    #+#             */
/*   Updated: 2020/02/03 12:48:57 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doubleon(int *a, int na, int *b, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (i < na && j < nb)
	{
		if (a[i] < b[j])
		{
			if (i == 0)
			{
				printf("%d", a[i]);
			}
			else
				printf(" %d", a[i]);
			i++;
		}
		else if (a[i] > b[j])
		{
			if (j == 0)
				printf("%d", b[j]);
			else
				printf(" %d", b[j]);
			j++;
		}
		else if (a[i] == b[j])
		{
			if (i == 0)
				printf("%d", a[i]);
			else
				printf(" %d", a[i]);
			i++;
			j++;
		}
	}
	if (i == na)
	{
		while (j < nb)
		{
			printf(" %d", b[j]);
			j++;
		}
	}
	else if (j == nb)
	{
		while (i < na)
		{
			printf(" %d", a[i]);
			i++;
		}
	}
	printf("\n");
}

int		main(void)
{

	int a[] = {0, 1, 2};
	int	na = 3;
	int b[] = {0, 1, 2, 3};
	int	nb = 4;
	print_doubleon(a, na, b, nb);

	
	int a1[] = {1, 2, 10, 15};
    int na1 = 4;
    int b1[] = {2, 20, 40, 70};
    int nb1 = 4;
	print_doubleon(a1, na1, b1, nb1);

	int a2[] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
    int na2 = 3;
    int b2[] = {2,  4,  5,  6,  7, 10,  40,  70};
    int nb2 = 4;
	print_doubleon(a2, na2, b2, nb2);

	int a3[] = {100,  200, 30};
    int na3 = 3;
    int b3[] = {1,    2,   3, 4};
    int nb3 = 4;
	print_doubleon(a3, na3, b3, nb3);
	return (0);
}
