#include "push_swap.h"

void	ft_pre_sort(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int	ft_median(t_vec *stack, size_t size, int *chunks)
{
	size_t i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	omm_guard(tab, __FILE__, __LINE__);
	while (i < stack->length)
	{
		vec_get(stack, i, &tab[i]);
		i++;
	}
	ft_pre_sort(tab, size);
	*chunks = *chunks + (size / 8);
	i = tab[*chunks];
	return (i);
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
	int	tmp;
	int	smallest;
	size_t	i;

	vec_get(stack, 0, &smallest);
	i = 1;
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
	int	tmp;
	int	biggest;
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
		write(1, "\nSA", 3);
	else if (opt == op_sb)
		write(1, "\nSB", 3);
	else if (opt == op_ss)
		write(1, "\nSS", 3);
	else if (opt == op_pa)
		write(1, "\nPA", 3);
	else if (opt == op_pb)
		write(1, "\nPB", 3);
	else if (opt == op_ra)
		write(1, "\nRA", 3);
	else if (opt == op_rb)
		write(1, "\nRB", 3);
	else if (opt == op_rr)
		write(1, "\nRR", 3);
	else if (opt == op_rra)
		write(1, "R\nRA", 4);
	else if (opt == op_rrb)
		write(1, "R\nRB", 4);
	else if (opt == op_rrr)
		write(1, "R\nRR", 4);
}

void	ft_exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}