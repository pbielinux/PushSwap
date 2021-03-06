/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:33:40 by pbielik           #+#    #+#             */
/*   Updated: 2021/10/10 22:33:41 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_check_dups(t_vec *stack);

void	ft_check_stack(t_vec *stack)
{
	if (!ft_check_dups(stack))
		ft_exit_error("Error: Doubles founded!\n");
	if (ft_is_sorted(stack))
		exit(EXIT_SUCCESS);
}

bool	ft_is_sorted(t_vec *stack)
{
	int		nb_current;
	int		nb_next;
	size_t	i;

	i = 0;
	while (i < stack->length - 1)
	{
		vec_get(stack, i, &nb_current);
		vec_get(stack, i + 1, &nb_next);
		if (nb_current > nb_next)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_rev_sorted(t_vec *stack)
{
	int		nb_current;
	int		nb_next;
	size_t	i;

	i = 0;
	while (i < stack->length - 1)
	{
		vec_get(stack, i, &nb_current);
		vec_get(stack, i + 1, &nb_next);
		if (nb_current < nb_next)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_dups(t_vec *stack)
{
	int		nb_current;
	int		nb_cmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->length)
	{
		vec_get(stack, i, &nb_current);
		j = i + 1;
		while (j < stack->length)
		{
			vec_get(stack, j, &nb_cmp);
			if (nb_current == nb_cmp)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
