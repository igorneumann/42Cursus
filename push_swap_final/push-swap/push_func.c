/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:34:39 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/18 21:06:50 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	ft_findsmaller(long *stk, int dig, int func, int buff)
{
	int	i;
	int	k[9999];

	i = 0;
	while (i < buff)
		k[i++] = 0;
	i = 0;
	k[0] = ft_findbiggerthan(stk, dig, -2147483648);
	while (++i < buff)
		k[i] = ft_findbiggerthan(stk, dig, stk[k[i - 1]]);
	return (k[func]);
}

int	ft_findbig(long *stk, int dig, int func, int buff)
{
	int			i;
	int			k[9999];

	i = 0;
	while (i < buff)
		k[i++] = 0;
	i = 0;
	k[0] = ft_findsmallerthan(stk, dig, 2147483649);
	while (++i < buff)
		k[i] = ft_findsmallerthan(stk, dig, stk[k[i - 1]]);
	return (k[func]);
}

void	ft_rrb(long *stk, long *stk2, int small, int dig)
{
	char	cad[3];

	cad[0] = 'r';
	cad[2] = 'b';
	while (small-- > 0)
	{
		cad[1] = 'r';
		ft_move(stk, stk2, dig, cad);
		printf ("rrb\n");
	}	
	ft_move(stk, stk2, dig, "pa");
	printf ("pa\n");
}

void	ft_rb(long *stk, long *stk2, int small, int dig)
{
	int	top;

	top = ft_findtop(stk2, dig);
	while (small++ < top)
	{
		ft_move(stk, stk2, dig, "rb");
		printf ("rb\n");
	}
	ft_move(stk, stk2, dig, "pa");
	printf ("pa\n");
}
