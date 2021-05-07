/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderhuge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ineumann          #+#    #+#             */
/*   Updated: 2021/05/07 20:315:15 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderhuge(long *stk, long *stk2, int dig)
{
	printf ("pase aqui");
	ft_orderwait(stk, stk2, dig, 15);
//	ft_orderwaitl(stk, stk2, dig, 15);
//	ft_orderwait(stk, stk2, dig, 5);
	ft_orderleft(stk, stk2, dig);
	ft_printstacks (stk, stk2, dig);
}

void	ft_orderwait (long *stk, long *stk2, int dig, int cut)
{
	int count;
	int	size;
	int topb;
	int small[cut];

	size = dig - 1;
	while (size > 0)
	{
		count = -1;
		while (++count < cut)
			small[count] = ft_findsmaller(stk2, dig, count);
		count = lessmov(small, dig, cut);
		if (count < (dig / 2))
			ft_rra(stk, stk2, count, dig);
		else
			ft_ra(stk, stk2, count, dig);
		count = ft_findtop(stk, dig) + 1;
		topb = ft_findtop(stk2, dig) + 1;
		ft_rrr (stk2, ft_stacks(topb, stk2), topb);
		size = ft_findtop(stk, dig) + 1;
		if (size < 2)
			break;
	}
}

void	ft_orderwaitl (long *stk, long *stk2, int dig, int cut)
{
	int count;
	int	size;
	int topb;
	int big[cut];

	size = dig - 1;
	while (size > 0)
	{
		count = -1;
		while (++count < cut)
			big[count] = ft_findbigger(stk2, dig, count);
		count = lessmov(big, dig, cut);
		if (count < (dig / 2))
			ft_rrb(stk, stk2, count, dig);
		else
			ft_rb(stk, stk2, count, dig);
		count = ft_findtop(stk, dig) + 1;
		topb = ft_findtop(stk2, dig) + 1;
		ft_rrr (stk, ft_stacks(count, stk), count);
		size = ft_findtop(stk, dig) + 1;
		if (size < 2)
			break;
	}
}

int lessmov(int *small,int dig, int cut)
{
	int moves[cut];
	int i;

	i = 0;
	while(i < cut)
	{
		if (small[i] > (dig / 2))
			moves[i] = (small[i] + 1);
		else
			moves[i] = (dig - small[i]);
		i++;
	}
	return ((int)small[ft_findsmaller((long*)moves, cut, 0)]);
}