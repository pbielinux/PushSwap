#include "push_swap.h"

void	ft_print_ops(t_opt opt)
{
	if (opt == op_sa)
		write(1, "SA\n", 3);
	else if (opt == op_sb)
		write(1, "SB\n", 3);
	else if (opt == op_ss)
		write(1, "SS\n", 3);
	else if (opt == op_pa)
		write(1, "PA\n", 3);
	else if (opt == op_pb)
		write(1, "PB\n", 3);
	else if (opt == op_ra)
		write(1, "RA\n", 3);
	else if (opt == op_rb)
		write(1, "RB\n", 3);
	else if (opt == op_rr)
		write(1, "RR\n", 3);
	else if (opt == op_rra)
		write(1, "RRA\n", 4);
	else if (opt == op_rrb)
		write(1, "RRB\n", 4);
	else if (opt == op_rrr)
		write(1, "RRR\n", 4);
}

void	ft_exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}