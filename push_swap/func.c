/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:39:13 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/14 20:13:59 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long* check_values (int argc, char **argv)
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
		return ((long*)1);
}

long* ft_convert_int (int argc, char **argv)
{
	int 		j;
	long int	*k;

	j = - 1;
	if (!(k = malloc(argc * sizeof(long int))))
		return ((long*)-1);
	while ((argc + j) >= 0)
	{
		k[argc + j] = ft_atoiswap(argv[argc + j]);
		if (k[argc + j] > 2147483648)
			return ((long*)1);
		j--;
	}
	k[0] = -1;
	return (ft_compare (k, argc));
}

long*	ft_compare (long *i, int argc)
{
	int j;
	int k;

	j = argc - 1;
	while (j >= 2)
	{
		k = j - 1;
		while (k >= 1)
		{
			if (i[j] == i[k])
				return ((long*)1);
			if (i[j] < i[k])
				i[0] = 0;
			k--;
		}
		j--;
	}
	return (i);
}

void	ft_printstacks (long *i, long *j, int dig)
{

	printf ("\n\n");
	while (--dig > 0)
	{
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
	printf ("\n");
}