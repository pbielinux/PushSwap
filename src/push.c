#include "push_swap.h"

void	ft_push(t_data *data, t_s_name stack_name)
{
	int	popped;

	if (stack_name == stack_a)
	{
		vec_get(&data->stack_b, 0, &popped);
		vec_shift(&data->stack_b);
		vec_unshift(&data->stack_a, &popped);
		ft_print_ops(op_pa);
	}
	else
	{
		vec_get(&data->stack_a, 0, &popped);
		vec_shift(&data->stack_a);
		vec_unshift(&data->stack_b, &popped);
		ft_print_ops(op_pb);
	}
}