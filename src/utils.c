#include "push_swap.h"

void	ft_pre_sort(int	*tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
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

void	ft_set_chunks(int *stack)
{
	//int	chunk_size;
	int	*stack_cpy;
	int	chunky[5][20];


	stack_cpy = malloc(sizeof(int) * 100);
	omm_guard(stack_cpy, __FILE__, __LINE__);
	memcpy(stack_cpy, stack, sizeof(int) * 100);


	ft_pre_sort(stack_cpy, 100);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
			chunky[i][j] = stack_cpy[i + j];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			ft_putnbr(chunky[i][j]);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
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
	ft_pre_sort(tab, stack->length);
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
	int	tmp;
	int	smallest;
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