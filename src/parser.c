#include "push_swap.h"

void	ft_parse_args(int nb_elems, char **to_sort)
{
	int	i;

	i = 0;
	while (i < nb_elems)
	{
		if (!ft_isnumber(to_sort[i]) || !ft_isint(to_sort[i]))
			exit(EXIT_FAILURE);
		i++;
	}
}

bool ft_isnumber(char *nb)
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

bool ft_isint(char *nb)
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