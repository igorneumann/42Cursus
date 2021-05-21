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
	ft_orderwait(stk, stk2, dig, 8.6);
	ft_orderleft(stk, stk2, dig);
}

void	ft_orderwait (long *stk, long *stk2, int dig, float cut)
{
	int count;
	int chunk;
	int	size;
	int topb;
	int small[dig];

	size = dig - 1;
	while (size > 0)
	{
		count = -1;
		chunk = 2147483647;
		if (chunk > (size / cut))
			chunk = (size / cut);
		while (++count < chunk)
			small[count] = ft_findsmaller(stk, size, count, chunk);
		count = lessmov(small, size, chunk);
		if (count < (size / 2))
			ft_rra(stk, stk2, count, dig);
		else
			ft_ra(stk, stk2, count, dig);
		topb = ft_findtop(stk2, dig) + 1;
		ft_rrr (stk2, ft_stacks(topb, stk2), topb);
		size = ft_findtop(stk, dig) + 1;
		if (size < 2)
			break;
	}
}

int lessmov(int *small, int dig, int cut)
{
	long moves[cut];

	int i;
	int j;

	i = 0;
	while(i < cut)
	{
		if (small[i] > (dig / 2))
			moves[i] = (dig - small[i]);
		else
			moves[i] = (small[i]);
		i++;
	}
	j = ft_findbest(moves, cut);
	return (small[j]);
}

int			ft_findbest(long *moves, int dig)
{
	int 		pos;
	long int	j;
	int			k;
	
	pos = 0;
	k = 0;
	j = 3000000000;
	while (++pos < dig)
	{
		if (moves[pos] < j)
		{
			j = moves[pos];
			k = pos;
		}
		if (j < 2)
			break;
	}
	return (k);
}