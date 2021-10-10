#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "types.h"

void	ft_parse_args(int nb_elems, char **to_sort);
void	ft_check_stack(t_vec *stack);
int		*ft_get_medians(t_data *data, int chunks);
bool	ft_is_sorted(t_vec *stack);

void	ft_push(t_data *data, t_s_name stack_name);
void	ft_swap(t_data *data, t_s_name stack_name);
void	ft_rotate(t_data *data, t_s_name stack_name);
void	ft_rev_rotate(t_data *data, t_s_name stack_name);
void	ft_print_ops(t_opt opt);

void	ft_sort_three(t_data *data);
void	ft_short_sort(t_data *data);
void	ft_sort_hundred(t_data *data);
void	ft_sort_large(t_data *data);
void 	ft_sort(t_data *data);

bool 	ft_isint(char *nb);
bool 	ft_isnumber(char *nb);

int		ft_median(t_vec *stack, size_t size);
int		ft_get_smallest(t_vec *stack);
int		ft_get_big(t_vec *stack);
size_t	ft_get_position(t_vec *stack, int nb);
void	ft_print_stacks(t_data *data);
void	ft_exit_error(char *msg);

#endif // !PUSH_SWAP_H