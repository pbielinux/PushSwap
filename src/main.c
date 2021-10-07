#include "push_swap.h"

static void	ft_print_usage(void);
void	ft_fill_stack(t_vec *stack, int nb_items, char **nb_value);

int main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		ft_print_usage();
	ft_parse_args(argc, argv);
	data.stack_a = vec_value((argc - 1), sizeof(int));
	data.stack_b = vec_value(1, sizeof(int));
	ft_fill_stack(&data.stack_a, (argc - 1), (argv + 1));
	ft_check_stack(&data.stack_a);

	if (data.stack_a.length < 8)
		ft_short_sort(&data);
	else if (data.stack_a.length <= 100)
		ft_sort_hundred(&data);
	
	vec_drop(&data.stack_a);
	vec_drop(&data.stack_b);
}

void	ft_fill_stack(t_vec *stack, int nb_items, char **nb_value)
{
	int i;
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