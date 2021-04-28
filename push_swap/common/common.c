/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:28:09 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/28 17:36:58 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

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
	int args;

	args = 1;
	while (argv[args])
	{
		if (ft_isdigit(argv[args]))
			if (argv[args - 1] == ' ')
				argc++;
		args++;
	}
	return(argc);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

