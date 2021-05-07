/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:02:36 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/07 21:07:06 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char*		ft_ordertree(long *stk, int dig)
{
	int bigger;

	bigger = ft_findbigger(stk, dig, 0);
	if (bigger == 3)
	{
		if (stk[2] > stk[1])
			return ("ra\nsa\n");
		else
			return ("ra\n");
	}
	else if (bigger == 2)
	{
		if (stk[3] > stk[1])
			return ("rra\n");
		else
			return ("sa\nra\n");
	}
	else
		return ("sa\n");
}