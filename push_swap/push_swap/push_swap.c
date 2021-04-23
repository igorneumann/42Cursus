/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:23:58 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/23 20:51:52 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	int			count;
	int			size;
	long int	*stk;
	long int	cad[argc];

	count = 0;
	while (count < argc)
		size = ft_find_args(argc, argv[count++]);
	if (size > 1)
	{
		stk = check_values(size, argv, cad);
		if (!(size == 2 || (stk[0] && stk[0] == -1)) && stk[0] == 0)
			ft_orderit(stk, ft_stacks(size, stk), size);
		else if (!(size == 2 || (stk[0] && stk[0] == -1)))
			printf("\n\033[0;31mERROR!\nERROR!\nERROR!\nVAS FATAL!\033[0m\n\n");
		return (0);
	}
	else
		ft_help();
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

void	ft_help(void)
{
	printf ("\033[0;31m\n  ** FALTAN LOS ARGUMENTOS **\n\n\033[0;34m");
	printf ("Argumentos son numeros enteros separados por espacio\n\n");
	printf ("El programa te dará la mejor combinación de movimientos\n\033[0m");
}