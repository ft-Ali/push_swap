/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:25:42 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:57:34 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	int				match_index;

	while (b)
	{
		match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < match_index)
			{
				match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == INT_MAX)
			b->target_node = ft_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
