/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:43:58 by hyu               #+#    #+#             */
/*   Updated: 2020/02/03 19:40:30 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct		s_node	{
	int				values;
	struct	s_node	**nodes;
};

int			height_tree(struct s_node *root)
{
	int		max_height;
	int		i;

	i = 0;
	//printf("%d", 1);
	if (root == 0)
		return (-1);
	if (root->nodes == 0 || *(root->nodes) == 0)
		return (0);
	max_height = height_tree(root->nodes[i]);
	i++;
	while (root->nodes[i] && root->nodes[i]->values)
    {
		if (height_tree(root->nodes[i]) > max_height)
			max_height = height_tree(root->nodes[i]);
        i++;
	}
	return (max_height + 1);
}

int			main(void)
{
	struct	s_node	*node1;
	struct	s_node	*node2;

	int		n1;
	int		n2;

	n1 = 10;
	n2 = 20;
	
	node1 = (struct s_node*)malloc(sizeof(struct s_node));
	node2 = (struct s_node*)malloc(sizeof(struct s_node));
	node1->values = n1;
	node2->values = n2;
	node1->nodes = (struct s_node**)malloc(sizeof(struct s_node*));
	node2->nodes = (struct s_node**)malloc(sizeof(struct s_node*));
	node1->nodes[0] = node2;
	node1->nodes[1] = 0;
	node2->nodes[0] = 0;
	printf("%d", height_tree(node1));
	/*
	printf("%d", node1->nodes[0]->values);
	int i;

	i = 0;
	while (node1->nodes[i] && node1->nodes[i]->values)
	{
		printf("%d", node1->nodes[i]->values);
		i++;
	}*/
	/*while (node1->nodes[0])
	{
		printf("%d", node1->values);
		node1 = node1->nodes[0];
	}*/
	return (0);
}
