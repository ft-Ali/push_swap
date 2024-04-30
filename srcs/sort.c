/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:35:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:57:51 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = ft_size_list(*a);
	if (size_a-- > 3 && !ft_sorted(*a))
		pb(b, a, false);
	if (size_a-- > 3 && !ft_sorted(*a))
		pb(b, a, false);
	while (size_a-- > 3 && !ft_sorted(*a))
	{
		init_a(*a, *b);
		a_to_b(a, b);
	}
	ft_sort_3(a);
	while (*b)
	{
		init_b(*a, *b);
		b_to_a(a, b);
	}
	current_index(*a);
	min_top(a);
}

// function pour que le cheapest soit aligne avec la target B
void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

// function pour que le cheapest soit aligne avec la target B
void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

// function qui check le cheapest puis check 
//c'est quoi le plus opti pour aligne avec ma target
void	a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	make_push(a, cheapest_node, 'a');
	make_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void	b_to_a(t_stack_node **a, t_stack_node **b)
{
	make_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}
