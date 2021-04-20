/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:02:36 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/20 20:48:42 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_orderit(long *stk, long *stk2, int dig)
{
	if (dig == 3)
		printf ("sa");
	else if (dig == 4)
		printf ("%s", ft_ordertree(stk, dig));
	else if (dig == 5)
	{
		ft_orderfour(stk, stk2, dig);
		printf ("pa\n");
	}
	else if (dig == 6)
	{
		ft_orderfive(stk, stk2, dig);
		printf ("pa\npa\n");
	}
}

char*		ft_ordertree(long *stk, int dig)
{
	if (ft_findbigger(stk, dig) == 3)
	{
		if (stk[2] > stk[1])
			return ("ra\nsa\n");
		else
			return ("ra\n");
	}
	else if (ft_findbigger(stk, dig) == 2)
	{
		if (stk[3] > stk[1])
			return ("rra\n");
		else
			return ("sa\nra\n");
	}
	else
		return ("sa\n");
}

void		ft_orderfour(long *stk, long *stk2, int dig)
{
	if (ft_findsmaller(stk, dig) == 4)
	{
		ft_move(stk, stk2, dig, "pb");
		printf ("pb\n");
	}
	else if (ft_findsmaller(stk, dig) == 3)
	{
		ft_move(stk, stk2, dig, "sa");
		ft_move(stk, stk2, dig, "pb");
		printf ("sa\npb\n");
	}
	else if (ft_findsmaller(stk, dig) == 2)
	{
		ft_move(stk, stk2, dig, "ra");
		ft_move(stk, stk2, dig, "ra");
		ft_move(stk, stk2, dig, "pb");
		printf ("ra\nra\npb\n");	
	}
	else
		ft_move(stk, stk2, dig, "ra");
		ft_move(stk, stk2, dig, "pb");
		printf ("rra\npb\n");
	printf ("%s", ft_ordertree(stk, dig));
}

void		ft_orderfive(long *stk, long *stk2, int dig)
{
	if (ft_findsmaller(stk, dig) == 5)
	{
		ft_move(stk, stk2, dig, "pb");
		printf ("pb\n");
	}
	else if (ft_findsmaller(stk, dig) == 4)
	{
		ft_move(stk, stk2, dig, "sa");
		ft_move(stk, stk2, dig, "pb");
		printf ("sa\npb\n");
	}
	else if (ft_findsmaller(stk, dig) == 3)
	{
		ft_move(stk, stk2, dig, "rra");
		ft_move(stk, stk2, dig, "rra");
		ft_move(stk, stk2, dig, "pb");
		printf ("ra\nra\npb\n");	
	}
	else if (ft_findsmaller(stk, dig) == 2)
	{
		ft_move(stk, stk2, dig, "ra");
		ft_move(stk, stk2, dig, "ra");
		ft_move(stk, stk2, dig, "pb");
		printf ("ra\nra\npb\n");	
	}
	else
		ft_move(stk, stk2, dig, "ra");
		ft_move(stk, stk2, dig, "pb");
		printf ("rra\npb\n");
	ft_orderfour(stk, stk2, dig);
}

int			ft_findbigger(long *stk, int dig)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dig-- > 1)
	{
		if (stk[dig] > j)
		{
			j = stk[dig];
			i = dig;
		}
	}
	return (i);
}

int			ft_findsmaller(long *stk, int dig)
{
	int 		i;
	long int	j;
	int			k;

	i = 0;
	j = 3000000000;
	while (i++ < dig)
	{
		if (stk[i] < j)
		{
			j = stk[i];
			k = i;
		}
	}
	return (k);
}