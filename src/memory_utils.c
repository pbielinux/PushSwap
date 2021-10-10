/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:21:03 by pbielik           #+#    #+#             */
/*   Updated: 2021/10/10 22:21:05 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freev(void **ptr, int len, bool free_seg)
{
	if (len < 0)
	{
		while (*ptr)
		{
			free(*ptr);
			*ptr++ = NULL;
		}
	}
	else
	{
		while (len >= 0)
		{
			free(ptr[len]);
			ptr[len--] = NULL;
		}
	}
	if (free_seg)
		free(ptr);
}

void	ft_free_data(t_data *data)
{
	if (data->argc > 2)
		ft_freev((void **)data->nb_value, data->nb_count - 1, true);
	vec_drop(&data->stack_a);
	vec_drop(&data->stack_b);
}

void	ft_exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
