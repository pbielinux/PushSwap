#include "push_swap.h"

void	ft_push(t_data *data, t_s_name stack_name)
{
	int	*popped;

	if (stack_name == stack_a)
	{
		popped = vec_pop(&data->stack_b);
		vec_push(&data->stack_a, popped);
	}
	else
	{
		popped = vec_pop(&data->stack_a);
		vec_push(&data->stack_b, popped);
	}
}