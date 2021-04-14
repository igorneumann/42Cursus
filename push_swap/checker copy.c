/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:07:31 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/12 20:07:35 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = check_values (argc, argv);
		if (i == -1 || argc == 2)
			printf ("OK");
		else if (i == 0)
			printf ("todos los argumentos son numeros enteros");
		else
		{
			printf ("error");
		
		}
	return (0);
	}
	else
		printf ("faltan los argumentos");
	return (1);
}

int check_values (int argc, char **argv)
{
	int i;
	int j;
	int k;
	i = 1;
	j = 0;
	k = 0;
		if (argc >= 3)
	{
		while (argv[i])
		{
			while (argv[i][k])
			{
				if (!ft_isdigit((int)argv[i][k]))
					if (argv[i][k] != '-' && argv[i][k] != '+')
						j++;
				k++;
			}
			k = 0;
			i++;
		}
	}
	if (j == 0)
		return (ft_convert_int(argc, argv));
	else
		return (1);
}

int ft_convert_int (int argc, char **argv)
{
	int 		j;
	long int	k[argc];
	t_int		*i;

	if (!(i = (t_int*)malloc(sizeof(t_int))))
		return (-1);
	k[argc - 1] = '\0';
	j = -1;
	while ((argc + j) >= 0)
	{
		k[argc - 1 + j] = ft_atoiswap(argv[argc + j]);
		if ((k[argc + j]) > 2147483648)
			return (1);
		j--;
	}
	i->value = k;
	return (ft_compare (i, argc));
}

int	ft_compare (t_int *i, int argc)
{
	int j;
	int k;
	int l;

	j = argc - 2;
	l = -1;
	while (j >= 1)
	{
		k = j - 1;
		while (k >= 0)
		{
			if (i->value[j] == i->value[k])
				return (1);
			if (i->value[j] < i->value[k])
				l = 0;
			k--;
		}
		j--;
	}
	return (l);
}