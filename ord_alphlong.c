/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:33:40 by hyu               #+#    #+#             */
/*   Updated: 2020/03/02 22:50:38 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef	struct s_point{
	char *str;
	int length;
	struct s_point *next;
}			t_point;

int	is_character(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int	word_num(char *str)
{
	int i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_character(str[i]) == 1 && 
				(is_space(str[i + 1]) == 1 || str[i + 1] == '\0'))
				word++;
		i++;
	}
	return (word);
}

void	skip_space(char *str, int *i)
{
	while (is_space(str[*i]) == 1 && str[*i] != '\0')
		*i = *i + 1;
}

void	skip_word(char *str, int *i)
{
	while (is_space(str[*i]) == 0 && str[*i] != '\0')
		*i = *i + 1;
}

char **ft_split(char *str)
{
	int	i;
	char **array;
	int words;
	int	num;

	num = 1;
	i = 0;
	words = word_num(str);
	array = (char **)malloc((words + 1)* sizeof(char*));
	skip_space(str, &i);
	array[0] = &str[i];
	skip_word(str, &i);
	if (str[i])
	{
		str[i] = '\0';
		i++;
	}
	while (num < words)
	{
		skip_space(str, &i);
		array[num] = &str[i];
		skip_word(str, &i);		
		if (str[i])
		{
			str[i] = '\0';
			i++;
		}
		num++;
	}
	return (array);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(char *stra, char *strb)
{
	int i;

	i = 0;
	while (stra[i] && strb[i] && stra[i] == strb[i])
	{
		i++;
	}
	return (stra[i] - strb[i]);
}

t_point *make_list(char *str)
{
	int words;
	char **array;
	t_point *list;
	t_point *head;
	int i;

	i = 0;
	
	words = word_num(str);
	array = ft_split(str);
	list = (t_point*)malloc(sizeof(t_point));
	head = list;
	while (i < words)
	{
		list->str = array[i];
		list->length = ft_strlen(array[i]);
		i++;
		if (i < words)
		{
			list->next = (t_point*)malloc(sizeof(t_point));
			list = list->next;
		}
	}
	list->next = NULL;
	return (head);
}

void	swap_values(t_point *a, t_point *b)
{
	t_point *tmp;

	tmp = (t_point*)malloc(sizeof(t_point*));
//	char *str;
//	int length;

	tmp->str = a->str;
	tmp->length = a->length;
	a->str = b->str;
	a->length = b->length;
	b->str = tmp->str;
	b->length = tmp->length;
}

void	bubble_sort(t_point *list)
{
	t_point *head;
	int	i;

	i = 1;
	head = list;
	while (i == 1)
	{
		i = 0;
		head = list;
		while (head && head->next)
		{
			if (head->length > head->next->length)
			{
				i = 1;
				swap_values(head, head->next);
			}
			head = head->next;
		}
	}
}

void	alph_sort(t_point *list)
{
	t_point *tmp;
	int	i;

	tmp = list;
	i = 1;

	while (i == 1)
	{
		i = 0;
		tmp = list;
		while (tmp && tmp->next)
		{
			if (tmp->length == tmp->next->length && ft_strcmp(tmp->str, tmp->next->str) > 0)
				{
					i = 1;
					swap_values(tmp, tmp->next);
				}
			tmp = tmp->next;
		}
	}
}

int main(int argc, char **argv)
{
	char *str;
	int	i;
	int j;
	char **str2;
	t_point *list;

	j = 0;
	if (argc >= 2)
	{
		str = argv[1];
		//i = word_num(str);
		//str2 = ft_split(str);
		//printf("%i", i);
		//while (j < i)
		//{
		//	printf("%s", str2[j]);
		//	j++;
		//}
		list = make_list(str);
		bubble_sort(list);
		alph_sort(list);
		while (list)
		{
			printf("%s", list->str);
			printf("%i", list->length);
			list = list->next;
		}
	}
	printf("\n");
	return (0);
}
