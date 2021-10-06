#include "push_swap.h"

static bool	ft_isnumber(char *nb);
static bool	ft_isint(char *nb);

void	ft_parse_args(int argc, char **to_sort)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(to_sort[i]) || !ft_isint(to_sort[i]))
			exit(EXIT_FAILURE);
		i++;
	}
}

static bool ft_isnumber(char *nb)
{
	if (*nb == '-')
		nb++;
	if (!*nb)
		return (false);
	while (*nb)
	{
		if (*nb < '0' || *nb > '9')
			return (false);
		nb++;
	}
	return (true);
}

static bool ft_isint(char *nb)
{
	char	*nb_char;

	nb_char = ft_itoa(ft_atoi(nb));
	if (ft_strlen(nb) != ft_strlen(nb_char)
		|| ft_strncmp(nb, nb_char, ft_strlen(nb)))
	{
		free(nb_char);
		return (false);
	}
	free(nb_char);
	return (true);
}