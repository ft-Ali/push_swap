/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:38:59 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:57:41 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ajout de node + du dernier node tout en mettant a jour *prev et *next
void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->push_cost = -1;
	node->index = -1;
	node->above_median = false;
	node->cheapest = false;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	fill_stack_a(t_stack_node **a, char **v, int c)
{
	int	n;
	int	i;

	i = 0;
	if (c == 2)
		v = ft_split(v[i], ' ');
	while (v[i])
	{
		n = ft_atoi(v[i]);
		add_node(a, n);
		i++;
	}
	if (c == 2)
		ft_free_split(v);
}
