/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:25:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:57:39 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/* check l'overflow (si je depasse le min ou max int) */

int	check_int(char *v)
{
	int		len;
	long	value;
	int		i;

	i = 0;
	while (v[i] == '0')
		i++;
	len = ft_strlen(&v[i]);
	value = ft_atol(v);
	if (len > 11 || value < INT_MIN)
		return (0);
	if (len > 11 || value > INT_MAX)
		return (0);
	return (1);
}

/* 
split_arg si j'ai que 2 argument ./push_swap "23 45 64"
skip les espaces et on check double check int et number
*/

void	split_arg(char **v)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (v[i])
	{
		args = ft_split(v[i], ' ');
		j = 0;
		while (args[j])
		{
			if (!ft_number(args[j]) || !check_int(args[j]) || !ft_double(args
					- 1))
				(ft_free_split(args), check_error());
			check_int(args[j]);
			j++;
		}
		ft_free_split(args);
		i++;
	}
}
/* si j'ai plusieurs arguments comme ./push_swap 23 42 -42
on check tout les arguments.
*/

int	check_arg(char **v)
{
	int	i;

	i = 1;
	while (v[i])
	{
		if (!ft_double(v) || !ft_number(v[i]) || !check_int(v[i]))
			check_error();
		i++;
	}
	return (1);
}
