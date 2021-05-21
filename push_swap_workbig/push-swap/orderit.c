/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:02:36 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/20 20:21:52 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_ordertree(long *stk, int dig)
{
	int	bigger;

	bigger = ft_findsmallerthan(stk, dig, 2147483649);
	if (bigger == 3)
	{
		if (stk[2] > stk[1])
		{
			ft_move(stk, stk, dig, "ra");
			ft_move(stk, stk, dig, "sa");
			return ("ra\nsa\n");
		}
		else
		{
			ft_move(stk, stk, dig, "ra");
			return ("ra\n");
		}
	}
	else if (bigger == 2)
		return (ft_ordertreetwo(stk, dig));
	else if (!(stk[1] < stk[2] < stk[3]))
	{
		ft_move(stk, stk, dig, "sa");
		return ("sa\n");
	}
	return (0);
}

char	*ft_ordertreetwo(long *stk, int dig)
{
	if (stk[3] > stk[1])
	{
		ft_move(stk, stk, dig, "rra");
		return ("rra\n");
	}
	else
	{
		ft_move(stk, stk, dig, "sa");
		ft_move(stk, stk, dig, "ra");
		return ("sa\nra\n");
	}
}

int	ft_findbiggerthan(long *stk, int dig, long smaller)
{
	int			i;
	long int	j;
	int			k;

	i = 0;
	k = 0;
	j = 3000000000;
	while (++i < dig)
	{
		if (stk[i] < j && stk[i] > smaller)
		{
			j = stk[i];
			k = i;
		}
	}
	return (k);
}

int	ft_findsmallerthan(long *stk, int dig, long bigger)
{
	int			i;
	long int	j;
	int			k;

	i = 0;
	k = 0;
	j = -3000000000;
	while (++i < dig)
	{
		if (stk[i] > j && stk[i] < bigger)
		{
			j = stk[i];
			k = i;
		}
	}
	return (k);
}
