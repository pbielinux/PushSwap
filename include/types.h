/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:20:05 by pbielik           #+#    #+#             */
/*   Updated: 2021/10/10 22:20:07 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "./libft/include/libft.h"

typedef enum e_stack_name
{
	stack_a,
	stack_b
}	t_s_name;

typedef enum e_operation
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr
}	t_opt;

typedef struct s_data
{
	t_vec	stack_a;
	t_vec	stack_b;
	size_t	nb_count;
	char	**nb_value;
	int		argc;
	int		*medians;
}	t_data;

#endif // !TYPES_H
