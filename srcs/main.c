/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:49:23 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:57:43 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// FUNCTION POUR TEST LE CODE

/* void	print_stack(t_stack_node *stack)
{
	if (stack == NULL)
	{
		ft_printf("La pile est vide.\n");
		return ;
	}
	while (stack != NULL)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_last_node(t_stack_node *stack)
{
	t_stack_node	*last_node;

	last_node = find_last(stack);
	if (last_node == NULL)
	{
		ft_printf("La pile est vide.\n");
		return ;
	}
	ft_printf("Details du dernier nœud :\n");
	ft_printf("Valeur : %d\n", last_node->nbr);
}

void	print_next_nodes(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*a;
	t_stack_node	*b;

	current_node = stack;
	while (current_node != NULL)
	{
		if (current_node->next == NULL)
		{
			ft_printf("Le prochain nœud du nœud %p est NULL.\n",
				(void *)current_node);
		}
		else
		{
			ft_printf("Le prochain nœud du nœud %p est : %p et sa valeur %d\n",
				(void *)current_node, (void *)(current_node->next),
				current_node->nbr);
		}
		current_node = current_node->next;
	}
} */
// FUNCTION POUR TEST LE CODE
int	main(int c, char **v)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (c == 1 || (c == 2 && !v[1][0]))
		return (0);
	else if (c == 2)
		split_arg(v);
	else if (c > 2)
		check_arg(v);
	fill_stack_a(&a, v + 1, c);
	if (!ft_sorted(a))
	{
		if (ft_size_list(a) == 2)
			sa(&a, false);
		else if (ft_size_list(a) == 3)
			ft_sort_3(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
