#include "push_swap.h"

static void	ft_print_usage(void);
static t_data ft_init_data(int nb_items, char **nb_value);

int main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		ft_print_usage();
	ft_parse_args(argc, argv);
	data = ft_init_data((argc - 1), (argv + 1));
	ft_check_stack(&data.stack_a);

/* 	int	tmp;
	for (size_t i = 0; i < data.stack_a.length; i++)
	{
		vec_get(&data.stack_a, i, &tmp);
		printf("%d\n", tmp);
	} */
}

static t_data ft_init_data(int nb_items, char **nb_value)
{
	t_data	data;
	int		i;
	int		tmp;

	data.nb_items = nb_items;
	data.stack_a = vec_value(nb_items, sizeof(int));
	data.stack_b = vec_value(1, sizeof(int));
	i = 0;
	while (i < nb_items)
	{
		tmp = ft_atoi(nb_value[i]);
		vec_set(&data.stack_a, i, &tmp);
		i++;
	}
	return (data);
}

static void	ft_print_usage(void)
{
	printf("Usage: ./push_swap int int int ...\n");
	exit(EXIT_FAILURE);
}