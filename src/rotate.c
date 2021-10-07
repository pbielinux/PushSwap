#include "push_swap.h"

void	ft_rotate(t_data *data, t_s_name stack_name)
{
	int	tmp;

	if (stack_name == stack_a)
	{
		vec_get(&data->stack_a, data->stack_a.length - 1, &tmp);
		vec_pop(&data->stack_a);
		vec_unshift(&data->stack_a, &tmp);
	}
}