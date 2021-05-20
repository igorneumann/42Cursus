/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:39:13 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/18 20:52:45 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-checker/checker.h"

long	*check_values (int argc, char **argv, long *cad)
{
	long	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (argc >= 2)
	{
		while (argv[++i[0]])
		{
			while (argv[i[0]][i[2]])
			{
				if (argv[i[0]][i[2]] && (argv[i[0]][i[2]] < '0'
					|| argv[i[0]][i[2]] > '9'))
					if (argv[i[0]][i[2]] != '-' && argv[i[0]][i[2]] != '+')
						i[1]++;
				i[2]++;
			}
			i[2] = 0;
		}
	}
	if (i[1] == 0)
		return (ft_convert_int(argc, argv, cad));
	else
		cad[0] = 4000000000;
	return (cad);
}

long	*check_args (int size, char *arg, long *cad)
{
	long	i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	if (size >= 3)
	{
		while (arg[k])
		{
			if (arg[k] == ' ')
				k++;
			if (arg[k] && (arg[k] < '0' || arg[k] > '9'))
				if (arg[k] != '-' && arg[k] != '+')
					j++;
			k++;
		}
		k = 0;
	}
	if (j == 0)
		return (ft_convert_arg(size, arg, cad));
	else
		cad[0] = 1;
	return (cad);
}

long	*ft_convert_int (int argc, char **argv, long *cad)
{
	int			j;
	long int	*k;

	j = 1;
	cad[0] = 0;
	k = malloc(argc * sizeof(long int));
	if (!k)
		cad[0] = 4000000000;
	while (j < argc && argv[j])
	{
		k[argc - j] = ft_atoiswap(argv[j]);
		if (k[argc - j] > 2147483648)
			cad[0] = 1;
		j++;
	}
	k[0] = -1;
	if (cad[0] == 0)
		return (ft_compare (k, argc));
	else
		return (cad);
}

long	*ft_convert_arg (int size, char *arg, long *cad)
{
	int			i;
	int			j;
	long int	*k;

	i = 0;
	j = 0;
	cad[0] = 0;
	k = malloc(size * sizeof(long int));
	if (!k)
		cad[0] = 4000000000;
	while ((j + 1) < size)
	{
		if ((i == 0 || arg[i] == ' ') && j++)
			k[size - j] = ft_atoiswap(&arg[i]);
		if (k[size - j] > 2147483648)
			cad[0] = 1;
		i++;
	}
	k[0] = 4000000000;
	if (cad[0] == 0)
		return (ft_compare (k, size));
	else
		return (cad);
}

long	*ft_compare (long *i, int argc)
{
	int	j;
	int	k;

	i[0] = -1;
	j = argc - 1;
	while (j >= 2)
	{
		k = j - 1;
		while (k >= 1)
		{
			if (i[j] == i[k])
			{
				i[0] = 4000000000;
				return (i);
			}
			else if (i[j] > i[k])
				i[0] = 0;
			k--;
		}
		j--;
	}
	return (i);
}
