/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:28:09 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/05 21:15:16 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-checker/checker.h"

long*	ft_stacks (int argc,long *stk)
{
	long int	*stk2;
	int 		i;
	
	i = 0;
	if (!(stk2 = malloc(argc * sizeof(long int))))
		return ((long*)-1);
	while (i < argc)
		stk2[i++] = 3000000000;
	stk[0] = 3000000000;
	return (stk2);	
}

int ft_findtop(long *stk, int dig)
{
	--dig;
	while (stk[dig] == 3000000000)
		--dig;
	return (dig);
}

int ft_find_args(int argc, char *argv)
{
	int pos;
	int size;

	size = argc;
	pos = 0;
	while (argv[pos++])
	{
		if (argv[pos] == ' ' || argv[pos] == '+' ||argv[pos] == '-')
			if (argv[pos + 1] > '0' && argv[pos + 1] < '9')
				size++;
	}
	return(size);
}

long int		ft_atoiswap(const char *n)
{
	long int i[3];

	if (n == NULL)
		return (3000000000);
	i[0] = 0;
	i[2] = 0;
	i[1] = 1;
	while (n[i[0]] == 32 || (n[i[0]] >= 9 && n[i[0]] <= 13))
		i[0]++;
	if (n[i[0]] < '0' && n[i[0]] > '9' && n[i[0]] != '-' && n[i[0]] != '+')
		return (0);
	if (n[i[0]] == '-' || n[i[0]] == '+')
		if (n[i[0]++] == '-')
			i[1] = (i[1] * (-1));
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