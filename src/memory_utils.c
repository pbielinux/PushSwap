#include "push_swap.h"

/* void	ft_freev(void **ptr, int len, bool free_seg)
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
} */

void	ft_free_data(t_data *data)
{
	//ft_freev((void **)data->nb_value, data->nb_count, true);
	vec_drop(&data->stack_a);
	vec_drop(&data->stack_b);
}