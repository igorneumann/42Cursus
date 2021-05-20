/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderhuge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ineumann          #+#    #+#             */
/*   Updated: 2021/05/18 21:15:19 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_orderhuge(long *stk, long *stk2, int dig)
{
	ft_orderwait(stk, stk2, dig, 8.6);
	ft_orderleft(stk, stk2, dig);
}

void	ft_orderwait (long *stk, long *stk2, int dig, float cut)
{
	int	count;
	int	chunk;
	int	top[2];
	int	small[9999];

	top[0] = dig - 1;
	while (top[0] > 0)
	{
		count = -1;
		chunk = 2147483647;
		if (chunk > (top[0] / cut))
			chunk = (top[0] / cut);
		while (++count < chunk)
			small[count] = ft_findsmaller(stk, top[0], count, chunk);
		count = lessmov(small, top[0], chunk);
		if (count < (top[0] / 2))
			ft_rra(stk, stk2, count, dig);
		else
			ft_ra(stk, stk2, count, dig);
		top[1] = ft_findtop(stk2, dig) + 1;
		ft_rrr (stk2, ft_stacks(top[1], stk2), top[1]);
		top[0] = ft_findtop(stk, dig) + 1;
		if (top[0] < 2)
			break ;
	}
}

int	lessmov(int *small, int dig, int cut)
{
	long	moves[9999];
	int		i;
	int		j;

	i = 0;
	while (i < cut)
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

int	ft_findbest(long *moves, int dig)
{
	int			pos;
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
			break ;
	}
	return (k);
}
