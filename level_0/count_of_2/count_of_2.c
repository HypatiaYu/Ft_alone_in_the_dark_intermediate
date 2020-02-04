/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:41:32 by hyu               #+#    #+#             */
/*   Updated: 2020/02/03 17:50:40 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	number_twos(int i, int *j)
{
	while (i != 0)
	{
		if (i % 10 == 2)
			*j = *j + 1;
		i = i / 10;
	}
}

int		count_of_2(int n)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i <= n)
	{
		number_twos(i, &j);
		i++;
	}
	return (j);
}
int		main(void)
{
	int i;

	i = count_of_2(25);
	printf("%d", i);
	return (0);
}
