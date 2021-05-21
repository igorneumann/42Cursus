/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:54:22 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/21 17:05:29 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-checker/checker.h"

void	ft_move(long *stk, long *stk2, int dig, char *cad)
{
	if (cad[0] == 's')
	{
		if (cad[1] == 'a')
			ft_swap(stk, dig);
		else if (cad[1] == 'b')
			ft_swap(stk2, dig);
	}
	else if (cad[0] == 'p')
	{
		if (cad[1] == 'b')
			ft_push(stk, stk2, dig);
		else if (cad[1] == 'a')
			ft_push(stk2, stk, dig);
		else if (cad[1] == 'r')
		{
			cad[2] = '\0';
			ft_printstacks (stk, stk2, dig);
		}
	}
	else if (cad[0] == 'r')
		ft_mover(stk, stk2, dig, cad);
	if (dig < 0)
		dig = -dig;
}

void	ft_mover(long *stk, long *stk2, int dig, char *cad)
{
	if (cad[1] == 'r' && (cad[2] == 'a' || cad[2] == 'b'))
	{
		dig = -dig;
		cad[1] = cad[2];
	}
	if (cad[1] != 'b' && ft_findtop(stk, dig) > 0)
		ft_rotate(stk, dig);
	if (cad[1] != 'a' && ft_findtop(stk2, dig) > 0)
		ft_rotate(stk2, dig);
}

void	ft_swap(long *stk, int dig)
{
	--dig;
	while (stk[dig] == 3000000000)
		--dig;
	stk[0] = stk[dig];
	stk[dig] = stk[dig - 1];
	stk[dig - 1] = stk[0];
	stk[0] = 3000000000;
}

void	ft_push(long *stk, long *stk2, int dig)
{
	int	top1;
	int	top2;

	top1 = dig - 1;
	while (stk[top1] == 3000000000 && top1 > 0)
		--top1;
	top2 = dig - top1;
	if (top1 > 0 && top2 > 0)
	{
		stk2[top2] = stk[top1];
		stk[top1] = 3000000000;
	}
}

void	ft_rotate(long *stk, int dig)
{
	int	i[2];

	i[1] = 0;
	if (dig < 0)
	{
		i[1] = 1;
		dig = -dig;
		i[0] = 1;
		stk[0] = stk[1];
	}
	dig = ft_findtop(stk, dig);
	if (i[1] == 0 && stk[dig] != 3000000000)
	{
		i[1] = -1;
		i[0] = dig;
		stk[0] = stk[dig];
	}
	while (i[0] <= dig && i[0] > 0)
	{
		stk[i[0]] = stk[i[0] + i[1]];
		i[0] = i[0] + i[1];
	}
	if (i[1] > 0)
		stk[dig] = stk[0];
	stk[0] = 3000000000;
}
