/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:22:08 by pbielik           #+#    #+#             */
/*   Updated: 2021/10/10 22:22:09 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_data *data, t_s_name stack_name)
{
	if (stack_name == stack_a)
	{
		if (data->stack_a.length < 2)
			return ;
		vec_swap(&data->stack_a, 0, 1);
		ft_print_ops(op_sa);
	}
	else
	{
		if (data->stack_b.length < 2)
			return ;
		vec_swap(&data->stack_b, 0, 1);
		ft_print_ops(op_sb);
	}
}
