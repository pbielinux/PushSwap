#include "push_swap.h"

static void	ft_print_usage(void);
void		ft_fill_stack(t_vec *stack, int nb_items, char **nb_value);

void	ft_freev(void **ptr, int len, bool free_seg)
{
    if (len < 0)
		while (*ptr)
		{
			free(*ptr);
			*ptr++ = NULL;
		}
    else
		while (len)
		{
			free(ptr[len]);
			ptr[len--] = NULL;
		}
    if (free_seg)
		free(ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		ft_print_usage();
	data.nb_value = &(argv[1]);
	data.nb_count = argc - 1;
	if (argc == 2)
	{
		data.nb_value = ft_split(argv[1], ' ');
		data.nb_count = ft_array_length((void **)data.nb_value);
	}
	ft_parse_args(data.nb_count, data.nb_value);
	data.stack_a = vec_value(data.nb_count, sizeof(int));
	data.stack_b = vec_value(data.nb_count, sizeof(int));
	ft_fill_stack(&data.stack_a, data.nb_count, data.nb_value);
	ft_check_stack(&data.stack_a);
	if (data.nb_count < 8)
		ft_short_sort(&data);
	else if (data.nb_count <= 100)
		ft_sort_hundred(&data);
	else
		ft_sort_large(&data);
	ft_freev((void **)data.nb_value, 100, true);
	ft_free_data(&data);
}

void	ft_fill_stack(t_vec *stack, int nb_items, char **nb_value)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < nb_items)
	{
		tmp = ft_atoi(nb_value[i]);
		vec_set(stack, i, &tmp);
		i++;
	}
}

static void	ft_print_usage(void)
{
	printf("Usage: ./push_swap int int int ...\n");
	exit(EXIT_FAILURE);
}
