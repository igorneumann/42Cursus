/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:34:39 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/23 20:46:27 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_stkdup(long int *s, int size)
{
	int		i;
	long	*pnt;

	i = size;
	pnt = malloc(i * sizeof(long));
	if (pnt == NULL)
		return (NULL);
	while (--i >= 0)
		pnt[i] = s[i];
	return (pnt);
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