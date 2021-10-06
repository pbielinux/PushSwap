#include "push_swap.h"

void ft_swap(t_vec *stack, t_s_name stack_name)
{
	if (stack->length < 2)
		return ;
	if (stack_name == stack_a)
	{
		vec_swap(stack, stack->length - 1, stack->length - 2);
		ft_print_ops(op_sa);
	}
	else
	{
		vec_swap(stack, stack->length - 1, stack->length - 2);
		ft_print_ops(op_sb);
	}
}