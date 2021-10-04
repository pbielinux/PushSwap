#include "push_swap.h"

bool	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	j = -1;
	while (++j < argc)
	{
		if (!ft_strncmp(argv[j], "-", 1) || !ft_strncmp(argv[j], "+", 1))
			return (false);
		i = -1;
		if (argv[j][0] == '-' || argv[j][0] == '+')
			i++;
		while (argv[j][++i])
			if (!ft_isdigit(argv[j][i]))
				return (false);
	}
	return (true);
}


int	check_arg(int argc, char **argv)
{
	int	i;

	i = -1;
	if (!check_digit(argc, argv))
		return (EXIT_FAILURE)
}	