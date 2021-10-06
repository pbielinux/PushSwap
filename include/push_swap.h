#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "types.h"

void	ft_parse_args(int argc, char **to_sort);
void	ft_check_stack(t_vec *stack);
bool	ft_is_sorted(t_vec *stack);

void	ft_swap(t_vec *stack, t_s_name stack_name);
void	ft_print_ops(t_opt opt);

void	ft_exit_error(char *msg);

#endif // !PUSH_SWAP_H