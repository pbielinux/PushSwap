#include "push_swap.h"

void	ft_rev_rotate(t_data *data, t_s_name stack_name)
{
	int	tmp;

	if (stack_name == stack_a)
	{
		vec_get(&data->stack_a, data->stack_a.length - 1, &tmp);
		vec_pop(&data->stack_a);
		vec_unshift(&data->stack_a, &tmp);
		ft_print_ops(op_rra);
	}
	else
	{
		vec_get(&data->stack_b, data->stack_b.length - 1, &tmp);
		vec_pop(&data->stack_b);
		vec_unshift(&data->stack_b, &tmp);
		ft_print_ops(op_rrb);
	}
}

void	ft_rotate(t_data *data, t_s_name stack_name)
{
	int	tmp;

	if (stack_name == stack_a)
	{
		vec_get(&data->stack_a, 0, &tmp);
		vec_shift(&data->stack_a);
		vec_set(&data->stack_a, data->stack_a.length, &tmp);
		ft_print_ops(op_ra);
	}
	else
	{
		vec_get(&data->stack_b, 0, &tmp);
		vec_shift(&data->stack_b);
		vec_set(&data->stack_b, data->stack_b.length, &tmp);
		ft_print_ops(op_rb);
	}
}