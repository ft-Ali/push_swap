/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:21:51 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:58:11 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack_node **top)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	int				tmp;

	if ((!(*top) || !top || !(*top)->next))
		return ;
	first_node = *top;
	second_node = (*top)->next;
	tmp = first_node->nbr;
	first_node->nbr = second_node->nbr;
	second_node->nbr = tmp;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	sa(a, true);
	sb(b, true);
	if (!print)
		ft_printf("ss\n");
}
/*
sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ss : sa et sb en même temps.
*/