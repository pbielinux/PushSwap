#include "push_swap.h"

void	ft_pre_sort(int stack[], int stack_length)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < stack_length - 1)
	{
		if (stack[i] > stack[i + 1])
		{
			tmp = stack[i];
			stack[i] = stack[i + 1];
			stack[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int	*ft_get_medians(t_data *data, int chunks)
{
	int	*medians;
	int	*stack_cpy;
	int	tmp;
	int i;

	medians = malloc(sizeof(int) * data->stack_a.length / chunks);
	omm_guard(medians, __FILE__, __LINE__);
	stack_cpy = malloc(sizeof(int) * data->stack_a.length);
	omm_guard(medians, __FILE__, __LINE__);
	i = 0;
	while (i < (int)data->stack_a.length)
	{
		vec_get(&data->stack_a, i, &tmp);
		stack_cpy[i] = tmp;
		i++;
	}
	ft_pre_sort(stack_cpy, data->stack_a.length);
	i = 1;
	while (i <= chunks)
	{
		medians[i - 1] = stack_cpy[data->nb_count / chunks * i - 1];
		i++;
	}
	free (stack_cpy);
	return (medians);
}

int	ft_median(t_vec *stack, size_t size)
{
	size_t	i;
	int		med;
	int		*tab;

	i = 0;
	tab = malloc(sizeof(int) * stack->length);
	omm_guard(tab, __FILE__, __LINE__);
	while (i < stack->length)
	{
		vec_get(stack, i, &tab[i]);
		i++;
	}
	//ft_pre_sort(tab, stack->length);
	(void)size;
	med = tab[0];
	free(tab);
	return (med);
}

size_t	ft_get_position(t_vec *stack, int nb)
{
	int	pos;
	int	tmp;

	pos = 0;
	vec_get(stack, 0, &tmp);
	while (tmp != nb)
	{
		vec_get(stack, pos, &tmp);
		pos++;
	}
	return (pos);
}

int	ft_get_smallest(t_vec *stack)
{
	int		tmp;
	int		smallest;
	size_t	i;

	i = 0;
	vec_get(stack, i, &smallest);
	while (i < stack->length)
	{
		vec_get(stack, i, &tmp);
		if (tmp < smallest)
			smallest = tmp;
		i++;
	}
	return (smallest);
}

int	ft_get_big(t_vec *stack)
{
	int		tmp;
	int		biggest;
	size_t	i;

	vec_get(stack, 0, &biggest);
	i = 1;
	while (i < stack->length)
	{
		vec_get(stack, i, &tmp);
		if (tmp > biggest)
			biggest = tmp;
		i++;
	}
	return (biggest);
}

void	ft_print_stacks(t_data *data)
{
	int	tmp;

	printf("A:\t");
	for (size_t i = 0; i < data->stack_a.length; i++)
	{
		vec_get(&data->stack_a, i, &tmp);
		printf("%d ", tmp);
	}
	printf("\n");
	printf("B:\t");
	for (size_t i = 0; i < data->stack_b.length; i++)
	{
		vec_get(&data->stack_b, i, &tmp);
		printf("%d ", tmp);
	}
	printf("\n---------------------------------------------------------\n");
}

void	ft_print_ops(t_opt opt)
{
	if (opt == op_sa)
		write(1, "sa\n", 3);
	else if (opt == op_sb)
		write(1, "sb\n", 3);
	else if (opt == op_ss)
		write(1, "ss\n", 3);
	else if (opt == op_pa)
		write(1, "pa\n", 3);
	else if (opt == op_pb)
		write(1, "pb\n", 3);
	else if (opt == op_ra)
		write(1, "ra\n", 3);
	else if (opt == op_rb)
		write(1, "rb\n", 3);
	else if (opt == op_rr)
		write(1, "rr\n", 3);
	else if (opt == op_rra)
		write(1, "rra\n", 4);
	else if (opt == op_rrb)
		write(1, "rrb\n", 4);
	else if (opt == op_rrr)
		write(1, "rrr\n", 4);
}

void	ft_exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
