/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:39:13 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/23 20:05:34 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long int		ft_atoiswap(const char *n)
{
	long int i[3];

	i[0] = 0;
	i[2] = 0;
	i[1] = 1;
	while (n[i[0]] == 32 || (n[i[0]] >= 9 && n[i[0]] <= 13))
		i[0]++;
	if (n[i[0]] < '0' && n[i[0]] > '9' && n[i[0]] != '-' && n[i[0]] != '+')
		return (0);
	if (n[i[0]] == '-' || n[i[0]] == '+')
	{
		if (n[i[0]] == '-')
			i[1] = (i[1] * (-1));
		i[0]++;
	}
	while (('9' >= n[i[0]]) && (n[i[0]] >= '0'))
	{
		i[2] = (i[2] * 10) + (n[i[0]] - '0');
		i[0]++;
		if (i[2] * i[1] > 2147483647)
			return (2147483649);
		else if (i[2] * i[1] < -2147483648)
			return (2147483649);
	}
	return (i[2] * i[1]);
}

long* check_values (int argc, char **argv, long *cad)
{
	long i;
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
				if (argv[i][k] == ' ')
					k++;
				if (argv[i][k] && !ft_isdigit((int)argv[i][k]))
					if (argv[i][k] != '-' && argv[i][k] != '+')
						j++;
				k++;
			}
			k = 0;
			i++;
		}
	}
	if (j == 0)
		return (ft_convert_int(argc, argv, cad));
	else
		cad[0] = 1;	
	return (cad);
}

long* ft_convert_int (int argc, char **argv, long *cad)
{
	int 		j;
	long int	*k;

	j = 1;
	cad[0] = 0;
	if (!(k = malloc(argc * sizeof(long int))))
		cad[0] = -1;
	while ((argc - j) > 0)
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

long*	ft_compare (long *i, int argc)
{
	int j;
	int k;

	i[0] = -1;
	j = argc - 1;
	while (j >= 2)
	{
		k = j - 1;
		while (k >= 1)
		{
			if (i[j] == i[k])
			{
				i[0] = 1;
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

void	ft_printstacks (long *i, long *j, int dig)
{
	printf ("\nS: A|B\n");
	while (--dig > 0)
	{
		printf ("%d: ", dig);
		if (i[dig] < 2147483647)
			printf ("%ld", i[dig]);
		else
			printf ("-");			
		printf ("|");
		if (j[dig] < 2147483647)
			printf ("%ld", j[dig]);
		else
			printf ("-");
		printf ("\n");
	}
	if (i[0] != 3000000000 || j[0] != 3000000000)
		printf ("\nWARNING: Buffer NOT CLEAN: %ld - %ld\n", i[0], j[0]);
	printf ("\n");
}