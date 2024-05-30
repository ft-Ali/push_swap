/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:47:09 by alsiavos          #+#    #+#             */
/*   Updated: 2024/05/13 13:18:48 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	ft_size_list(t_stack_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	ft_sort_3(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = ft_max_node(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

// a la toute fin mon min se retrouve tout en bas de ma pile
// je la fais remonter a sa place 
// si au dessus de median ra sinon rra
void	min_top(t_stack_node **a)
{
	while ((*a)->nbr != ft_min_node(*a)->nbr)
	{
		if (ft_min_node(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

// function qui met mon top_node au top de ma stack
void	make_push(t_stack_node **stack, t_stack_node *top_node, char pile)
{
	while (*stack != top_node)
	{
		if (pile == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (pile == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
