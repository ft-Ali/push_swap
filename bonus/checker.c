/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:25:59 by alsiavos          #+#    #+#             */
/*   Updated: 2024/05/13 13:12:28 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_2(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[2] == 'a')
		rra(a, true);
	else if (line[2] == 'b')
		rrb(b, true);
	else if (line[2] == 'r')
		rrr(a, b, true);
}

char	*ft_check(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a, true);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b, true);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b, true);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(b, a, true);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a, true);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b, true);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_2(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b, true);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b, true);
	else
		(free_stack(a), free_stack(b), free(line), check_error());
	return (get_next_line(0));
}

void	ft_checker(t_stack_node **a, t_stack_node **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		ft_printf("KO\n");
	else if (!ft_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

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
} */

int	main(int c, char **v)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	a = NULL;
	b = NULL;
	if (c == 1 || (c == 2 && !v[1][0]))
		return (0);
	else if (c == 2)
		split_arg(v);
	else if (c > 2)
		check_arg(v);
	fill_stack_a(&a, v + 1, c);
	line = get_next_line(0);
	if (!line && !ft_sorted(a))
		ft_printf("KO\n");
	else if (!line && ft_sorted(a))
		ft_printf("OK\n");
	else
		ft_checker(&a, &b, line);
	free_stack(&a);
	free_stack(&b);
}
