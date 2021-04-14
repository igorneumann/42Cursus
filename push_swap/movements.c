/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:54:22 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/14 21:03:40 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_orders(long *stk, long *stk2, int dig)
{
	char		cad[4];
	int			i;

	i = 4;
	while (i-- > 0)
		cad[i] = '\0';
	ft_printstacks (stk, stk2, dig);
	printf ("Tus ordenes:\n");	
	read(0, cad, 3);
	if (cad[0] > 96 && cad[0] < 116 && cad[1] > 96 && cad[1] < 116)
	{
		ft_move(stk, stk2, dig, cad);
	}
}


void			ft_move(long *stk, long *stk2, int dig, char *cad)
{
	printf ("Escribiste: %s", cad);
	if (cad[0] == 's')
	{
		if (cad[1] == 'a' || cad[1] == 's' )
			ft_swap(stk, dig);
		if (cad[1] == 'b' || cad[1] == 's' )
			ft_swap(stk2, dig);
	}
	else if (cad[0] == 'p')
	{
		if (cad[1] == 'a')
			ft_push(stk, stk2, dig);
		if (cad[1] == 'b')
			ft_push(stk2, stk, dig);
	}
	else if (cad[0] == 'r')
	{
		if (cad[2] > 96 && cad[2] < 116)
		{
			printf("3 digitos");
			dig = -dig;
			cad[1] = cad[2];
		}
		//printf ("cad1 es %c\ncad2 es %c\ndig es %d\n", cad[1], cad[2], dig);
		if (cad[1] != 'b')
		{
			printf("condicion1");
			ft_rotate(stk, dig);
		}
		if (cad[1] != 'a')
		{
			printf("condicion2");
			ft_rotate(stk2, dig);
		}
	}
ft_printstacks (stk, stk2, dig);
}

void			ft_swap(long *stk, int dig)
{
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
	printf ("hola");
	stk[0] = stk[--dig];
	while (dig > 0)
		stk[dig] = stk[dig - 1];
	stk[0] = 3000000000;
}
/*
ra	push 1st element a become last
rb	push 1st element b to last
rr	push 1st elements A and B to bottom
rra reverse rotation A last element become 1st
rrb reverse rotation B last element become 1st
rrr reverse rotation B last element become 1st
*/