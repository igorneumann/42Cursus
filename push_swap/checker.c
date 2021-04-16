/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:07:31 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/16 20:24:31 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	long int	*stk;
	long int	cad[argc];

	if (argc > 1)
	{
		stk = check_values(argc, argv, cad);
		if (argc == 2 || (stk[0] && stk[0] == -1))
			printf("OK\n\033[0;34mOK? ERES EL MEJOR Y LO SABES!\033[0m\n");
		else if (stk[0] == 0)
		{
			printf("\nTodos los argumentos son numeros enteros\n");
			ft_orders (stk, ft_stacks(argc, stk), argc);
			if (stk[0] == -1)
				printf("OK\n\033[0;34mOK? ERES EL MEJOR Y LO SABES!\033[0m\n");
			else
				printf("KO\n\033[0;31mBOOO, ESTA MAL!\033[0m\n\n");
		}
		else
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
	printf ("Posteriormente el programa pedira los movimientos\n\033[0m");
	printf ("Uno a la vez o todos en la misma linea separados por espacio\n\n");
	printf ("\033[0;34mLos movimientos posible son:\n\n\033[0m");
	printf ("sa: swap a - intercambia los primeros 2 elementos en A. \n");
	printf ("sb: swap b - intercambia los primeros 2 elementos en B. \n");
	printf ("ss: sa y sb al mismo tiempo.\n");
	printf ("pa: empuje a - tome el primer elemento de B y colóquelo en A.\n"); 
	printf ("pb: empuje b - tome el primer elemento de A y colóquelo en B.\n");
	printf ("ra: rotate a - desplaza hacia arriba los elementos de A en 1.\n");
	printf ("rb: rotate b - desplaza hacia arriba los elementos de B en 1.\n");
	printf ("rr: ra y rb al mismo tiempo.\n");
	printf ("rra: reverse rotate a - desplaza abajo los elementos de A\n");
	printf ("rrb: reverse rotate b - desplaza abajo los elementos de B\n");
	printf ("rrr: rra y rrb al mismo tiempo.\n\n");
}


