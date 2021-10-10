/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:53:42 by pbielik           #+#    #+#             */
/*   Updated: 2021/10/10 22:53:43 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
