/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:53:57 by hyu               #+#    #+#             */
/*   Updated: 2020/02/03 20:00:22 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct	s_node{
		int				value;
		struct	s_node	*right;
		struct	s_node	*left;
};

void	reverse_tree(struct s_node *root);

int		main(void)
{
	struct	s_node	*node1;
	struct

	node1 = (struct s_node*)malloc(sizeof(struct s_node*));
	printf("%d", 3);
	return (0);
}
