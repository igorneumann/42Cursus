/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:54:22 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/22 19:24:47 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_orders(long *stk, long *stk2, int dig)
{
	char		cad[4];

	ft_printstacks (stk, stk2, dig);
	printf ("Tus ordenes ('inexistente' o vacio para terminar):\n");	
	read(0, &cad[0], 1);
	while (cad[0] < 97 && cad[0] != 10)
		read(0, &cad[0], 1);
	if (cad[0] == 's' || cad[0] == 'p' || cad[0] == 'r')
		read(0, &cad[1], 1);
	if (cad[1] == 'r')
		read(0, &cad[2], 1);
	else
		cad[2] = '\0';
	if (cad[0] == 's' || cad[0] == 'p' || cad[0] == 'r')
		read(0, &cad[3], 1);
	cad[3] = '\0';
	if (cad[0] == 's' || cad[0] == 'p' || cad[0] == 'r')
		printf ("Exec %s:\n", cad);
	if ((cad[0] == 's' || cad[0] == 'p' || cad[0] == 'r') &&
		(cad[1] == 'a' || cad[1] == 'b' || 
		(cad[1] == 'r' && (cad[2] == 'a' || cad[2] == 'b' ))))
	{
		ft_move(stk, stk2, dig, cad);
		ft_orders(stk, stk2, dig);
	}
	else 
		ft_compare(stk, dig);
}


void			ft_move(long *stk, long *stk2, int dig, char *cad)
{
	if (cad[0] == 's')
	{
		if (cad[1] == 'a' || cad[1] == 's' )
			ft_swap(stk, dig);
		if (cad[1] == 'b' || cad[1] == 's' )
			ft_swap(stk2, dig);
	}
	else if (cad[0] == 'p')
	{
		if (cad[1] == 'b')
			ft_push(stk, stk2, dig);
		if (cad[1] == 'a')
			ft_push(stk2, stk, dig);
	}
	else if (cad[0] == 'r')
	{
		if (cad[1] == 'r' && cad[2])
		{
			dig = -dig;
			cad[1] = cad[2];
		}
		if (cad[1] != 'b' && cad[2] != 'b')
			ft_rotate(stk, dig);
		if (cad[1] != 'a' && cad[2] != 'a')
			ft_rotate(stk2, dig);
	}
	if (dig < 0)
		dig = -dig;
}

void			ft_swap(long *stk, int dig)
{
	--dig;
	while (stk[dig] == 3000000000)
		--dig;
	stk[0] = stk[dig];
	stk[dig] = stk[dig - 1];
	stk[dig - 1] = stk[0];
	stk[0] = 3000000000;
}

void			ft_push(long *stk, long *stk2, int dig)
{
	int top1;
	int top2;

	top1 = dig - 1;
	while (stk[top1] == 3000000000 && top1 > 0)
		--top1;
	top2 = dig - top1;
	stk2[top2] = stk[top1];
	stk[top1] = 3000000000;
}

void			ft_rotate(long *stk, int dig)
{
	int i;
	int j;

	j = 0;
	if (dig < 0)
	{
		j = 1;
		dig = -dig;
		i = 1;
		stk[0] = stk[1];
	}
	dig = ft_findtop(stk, dig);
	if (j == 0)
	{
		j = -1;
		i = dig;
		stk[0] = stk[dig];
	}
	while (i <= dig && i > 0)
	{
		stk[i] = stk[i + j];
		i = i + j;
	}
	if (j > 0)
		stk[dig] = stk[0];
	stk[0] = 3000000000;
}