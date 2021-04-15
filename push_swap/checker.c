/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:07:31 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/15 21:01:14 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	long int	*stk;
	long int	*stk2;
	long int	cad[argc];

	if (argc > 1)
	{
		stk = check_values(argc, argv, cad);
		if (argc == 2 || (stk[0] && stk[0] == -1))
			printf("OK\n");
		else if (stk[0] == 0)
		{
			printf("todos los argumentos son numeros enteros\n");
			stk2 = ft_stacks(argc, stk);
			ft_orders (stk, stk2, argc);
			if (stk[0] == -1)
				printf("OK\n");
			else
				printf("BOOO, ESTA MAL!\n");
		}
		else
			printf("error\n");
		return (0);
	}
	else
		printf ("faltan los argumentos\n");
	return (1);
}

long*	ft_stacks (int argc,long *stk)
{
	long int	*stk2;
	int 		i;
	
	i = 0;
	if (!(stk2 = malloc(argc * sizeof(long int))))
		return ((long*)-1);
	while (i < argc)
		stk2[i++] = 3000000000;
	stk[0] = 3000000000;
	return (stk2);	
}

