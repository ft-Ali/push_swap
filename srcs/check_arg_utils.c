/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:49:56 by alsiavos          #+#    #+#             */
/*   Updated: 2024/04/29 11:57:36 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sign(char c)
{
	return (c == '+' || c == '-');
}

int	mydigit(char c)
{
	return (c >= '0' && c <= '9');
}
/*check si j'ai que des numbers est pas d'autres character ou bien un signe
 en solo comme "23-4 -+ + - 10- etc.." */

int	ft_number(char *v)
{
	int	i;

	i = 0;
	if (ft_sign(v[i]) && v[i + 1] != '\0')
		i++;
	while (v[i] && mydigit(v[i]))
		i++;
	if (v[i] != '\0' && !mydigit(v[i]))
		return (0);
	return (1);
}
/* check les doublons, et skip les 0 inutiles 
comme "000002" avec atoi avec l'arguments suivant */

int	ft_double(char **v)
{
	int	i;
	int	j;

	i = 1;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			if (ft_atoi(v[i]) == ft_atoi(v[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
