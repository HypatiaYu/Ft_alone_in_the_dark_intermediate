/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:09:51 by hyu               #+#    #+#             */
/*   Updated: 2020/02/03 17:27:47 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>

int		check(int A, int B, int C, int n)
{
	if ((A + C) * 10 + (B + A) == n)
		return (1);
	return (0);
}

void    equation(int n)
{
	int A;
	int B;
	int C;

	A = 0;
	B = 0;
	C = 0;
	while (A < 10)
	{
		B = 0;
		while (B < 10)
		{
			C = 0;
			while (C < 10)
			{
				if (check(A, B, C, n) == 1)
					printf("A = %d, B = %d, C = %d\n", A, B, C);
				C++;
			}
			B++;
		}
		A++;
	}
}

int		ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	return (j);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		i = ft_atoi(argv[1]);
		equation(i);
	}
	return (0);
}
