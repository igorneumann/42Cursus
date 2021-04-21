/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:07:50 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/21 18:35:21 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderbig(long *stk, long *stk2, int dig)
{
	int half;
	int small;
	int stka;

	half = dig / 2;
	stka = dig;
	while (stka-- > 3)
	{
		small = ft_findsmaller(stk, dig);
		if (small < half)
			ft_rra(stk, stk2, small, dig);
		else
			ft_ra(stk, stk2, small, dig);
		printf ("pb\n");
	}
}


void		ft_rra(long *stk, long *stk2, int small, int dig)
{
	int	 neg;
	
	neg = dig * -1;
	printf ("small is %i - dig is %i - neg is %i\n", small, dig, neg);
	while (small-- > 0)
	{
		ft_move(stk, stk2, neg, "rra");
		printf ("rra\n");
	}	
}
void		ft_ra(long *stk, long *stk2, int small, int dig)
{
	while (small++ < (dig - 1))
	{
		ft_move(stk, stk2, dig, "ra");
		printf ("ra\n");
	}	
}