/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:28:52 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:57:31 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	cost_check_a(a, b);
	cheapest(a);
}

// met a jour la median / repere si je suis au dessus ou en dessous de la median
void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_size_list(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

// trouver la target de A dans B le plus proche si pas de proche MIN on
// cherche le MAX de A
void	target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	int				match_index;

	while (a)
	{
		match_index = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > match_index)
			{
				match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (match_index == INT_MIN)
			a->target_node = ft_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

/* void	cost_check_a(t_stack_node *pile_a, t_stack_node *pile_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_size_list(pile_a);
	size_b = ft_size_list(pile_b);
	while (pile_a)
	{
		pile_a->push_cost = pile_a->index;
		if (pile_a->above_median && pile_a->target_node->above_median)
			pile_a->push_cost += pile_a->index + pile_a->target_node->index;
		if ((pile_a->above_median) && !(pile_a->target_node->above_median))
			pile_a->push_cost += pile_a->index + (size_b
					- pile_a->target_node->index);
		if (!(pile_a->above_median) && !(pile_a->target_node->above_median))
			pile_a->push_cost += (size_a - pile_a->target_node->index) + (size_b
					- pile_a->target_node->index);
		if (!(pile_a->above_median) && (pile_a->target_node->index))
			pile_a->push_cost += (size_a - pile_a->index)
				+ pile_a->target_node->index;
		pile_a = pile_a->next;
	}
} */

// calcul du cout pour chaque element de A par rapport 
//a son index/median de A pour B
void	cost_check_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_size_list(a);
	len_b = ft_size_list(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	cheapest(t_stack_node *stack)
{
	int				cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
