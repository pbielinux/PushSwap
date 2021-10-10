/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:37:18 by pbielik           #+#    #+#             */
/*   Updated: 2021/10/10 22:37:24 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_b_to_a(t_data *data);

void	ft_sort_large(t_data *data, int chunks)
{
	int	*chunk_max;
	int	smallest;
	int	tmp;
	int	i;

	i = 0;
	chunk_max = ft_get_medians(data, chunks);
	smallest = ft_get_smallest(&data->stack_a);
	while (i < chunks && data->stack_a.length > 3)
	{
		while (smallest < chunk_max[i])
		{
			smallest = ft_get_smallest(&data->stack_a);
			vec_get(&data->stack_a, 0, &tmp);
			if (tmp <= chunk_max[i])
				ft_push(data, stack_b);
			else
				ft_rotate(data, stack_a);
			if (data->stack_a.length < 1)
				break ;
		}
		i++;
	}
	free(chunk_max);
	ft_push_b_to_a(data);
}

static void	ft_push_b_to_a(t_data *data)
{
	size_t	size;
	int		big;

	while (data->stack_b.length > 0)
	{
		big = ft_get_big(&data->stack_b);
		size = data->stack_b.length;
		if (ft_get_position(&data->stack_b, big) < size / 2)
			while (ft_get_position(&data->stack_b, big) != 0)
				ft_rotate(data, stack_b);
		else
			while (ft_get_position(&data->stack_b, big) != 0)
				ft_rev_rotate(data, stack_b);
		ft_push(data, stack_a);
	}
}
