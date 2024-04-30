/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:06:27 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:58:24 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include ".libft/gnl/get_next_line.h"
# include ".libft/libft.h"
# include ".libft/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

/************************************
				STRUCT
*************************************/

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/************************************
				PARSING
*************************************/

int						ft_double(char **v);
int						ft_number(char *v);
int						mydigit(char c);
int						ft_sign(char c);
int						check_int(char *v);
int						check_arg(char **v);
void					check_error(void);
void					split_arg(char **v);

/************************************
				STACK INIT
*************************************/

void					fill_stack_a(t_stack_node **a, char **v, int c);
void					add_node(t_stack_node **stack, int n);

/************************************
				NODES UTILS
*************************************/
void					free_stack(t_stack_node **stack);
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*ft_max_node(t_stack_node *stack);
t_stack_node			*ft_min_node(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);
/************************************
				NODES
*************************************/
bool					ft_sorted(t_stack_node *stack);
int						ft_size_list(t_stack_node *stack);
void					current_index(t_stack_node *stack);
void					target_a(t_stack_node *a, t_stack_node *b);
void					target_b(t_stack_node *a, t_stack_node *b);
void					cost_check_a(t_stack_node *pile_a,
							t_stack_node *pile_b);
void					cheapest(t_stack_node *stack);
void					make_push(t_stack_node **stack, t_stack_node *top_node,
							char pile);
void					init_a(t_stack_node *a, t_stack_node *b);
void					init_b(t_stack_node *a, t_stack_node *b);
void					a_to_b(t_stack_node **a, t_stack_node **b);
void					b_to_a(t_stack_node **a, t_stack_node **b);
void					min_top(t_stack_node **a);

/************************************
				COMMANDS
*************************************/

/*------------------------PB PA---------------------------*/

void					push(t_stack_node **dst, t_stack_node **src);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);

/*------------------------SA SB SS---------------------------*/

void					swap(t_stack_node **top);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);

/*-----------------------RA RB RR-----------------------------*/

void					rotate(t_stack_node **stack);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

/*-----------------------RRA RRB RRR-----------------------------*/

void					reverse_rotate(t_stack_node **stack);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

/************************************
				ALGO
*************************************/
void					sort_stack(t_stack_node **a, t_stack_node **b);
void					ft_sort_3(t_stack_node **a);

/************************************
				BONUS/CHECKER
*************************************/

void					ft_checker(t_stack_node **a, t_stack_node **b,
							char *line);
char					*ft_check(t_stack_node **a, t_stack_node **b,
							char *line);
void					ft_check_2(t_stack_node **a, t_stack_node **b,
							char *line);

#endif
