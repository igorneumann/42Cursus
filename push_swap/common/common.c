/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:28:09 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/30 21:01:10 by ineumann         ###   ########.fr       */
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

	pos = 1;
	while (argv[pos])
	{
		if (argv[pos] == ' ')
			if (argv[pos + 1] < '0' || argv[pos + 1] > '9')
				argc++;
		pos++;
	}
	return(argc);
}