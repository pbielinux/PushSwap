/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:21:43 by pbielik           #+#    #+#             */
/*   Updated: 2021/10/10 22:21:44 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_a_till_small(t_data *data);

void	ft_short_sort(t_data *data)
{
	while (data->stack_a.length > 3)
	{
		ft_rotate_a_till_small(data);
		ft_push(data, stack_b);
	}
	if (!ft_is_sorted(&data->stack_a))
		ft_sort_three(data);
	while (data->stack_b.length > 0)
		ft_push(data, stack_a);
}

void	ft_sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	vec_get(&data->stack_a, 0, &top);
	vec_get(&data->stack_a, 1, &mid);
	vec_get(&data->stack_a, 2, &bot);
	if (top > mid && mid < bot && bot > top)
		ft_swap(data, stack_a);
	else if (top > mid && mid > bot && bot < top)
	{
		ft_swap(data, stack_a);
		ft_rev_rotate(data, stack_a);
	}
	else if (top > mid && mid < bot && bot < top)
		ft_rotate(data, stack_a);
	else if (top < mid && mid > bot && bot > top)
	{
		ft_swap(data, stack_a);
		ft_rotate(data, stack_a);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_rev_rotate(data, stack_a);
}

static void	ft_rotate_a_till_small(t_data *data)
{
	size_t	moves;
	int		small;
	int		top;	

	small = ft_get_smallest(&data->stack_a);
	moves = ft_get_position(&data->stack_a, small);
	vec_get(&data->stack_a, 0, &top);
	if (moves <= (data->stack_a.length / 2))
	{
		while (top != small)
		{
			ft_rotate(data, stack_a);
			vec_get(&data->stack_a, 0, &top);
		}
	}
	else
	{
		while (top != small)
		{
			ft_rev_rotate(data, stack_a);
			vec_get(&data->stack_a, 0, &top);
		}
	}
}
