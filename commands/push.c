/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:56:57 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:58:04 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*top_node;

	if (!(*src))
		return ;
	top_node = *src;
	*src = (*src)->next;
	top_node->next = *dst;
	*dst = top_node;
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	if (!*b)
		return ;
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	if (!*a)
		return ;
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
