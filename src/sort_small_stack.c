#include "push_swap.h"

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

void	ft_rotate_till_small(t_data *data)
{
	size_t	moves;
	int		small;
	int		top;	

	small = ft_get_smallest(&data->stack_a);
	moves = ft_get_position(&data->stack_a, small);
	vec_get(&data->stack_a, 0, &top);
	if (moves < (data->stack_a.length / 2))
		while (top != small)
		{
			ft_rotate(data, stack_a);
			vec_get(&data->stack_a, 0, &top);
		}
	else
		while (top != small)
		{
			ft_rev_rotate(data, stack_a);
			vec_get(&data->stack_a, 0, &top);
		}
}

void	ft_short_sort(t_data *data)
{
	while (data->stack_a.length > 3)
	{
		ft_rotate_till_small(data);
		ft_push(data, stack_b);
	}
	if (!ft_is_sorted(&data->stack_a))
		ft_sort_three(data);
	while (data->stack_b.length > 0)
		ft_push(data, stack_a);
}

void	ft_sort_hundred(t_data *data)
{
	int	med;
	int	size;
	int	tmp;

	data->chunks = 0;
	size = data->stack_a.length;
	while (data->stack_a.length > 3)
	{
		med = ft_median(&data->stack_a, size);
		while (ft_get_smallest(&data->stack_a) < med)
		{
			vec_get(&data->stack_a, 0, &tmp);
			if (tmp < med)
				ft_push(data, stack_b);
			else
				ft_rotate(data, stack_a);
		}
	}
	ft_sort_three(data);
	ft_sort(data);
}

void 	ft_sort(t_data *data)
{
	size_t	size;
	int	big;

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