#ifndef TYPES_H
# define TYPES_H

# include "./libft/include/libft.h"

typedef struct s_stack
{
	t_list	*first;
	int		count;
	int		min;
	int		max[3];
}	t_stack;

typedef struct s_data
{
	t_stack *stack_a;
	t_stack *stack_b;
	char	**argv;
}	t_data;

#endif // !TYPES_H