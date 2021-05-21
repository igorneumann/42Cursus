/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:07:31 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/17 19:26:36 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main (int argc, char **argv)
{
	int			count;
	int			size;
	long int	*stk;
	long int	cad[argc];

	count = 0;
	if (argc > 1)
	{
		size = ft_find_args(argc, argv[1]);
		if (size != argc)
			stk = check_args(size, argv[1], cad);				
		else
			stk = check_values(size, argv, cad);	
		if (stk[0] && stk[0] == -1)
			printf("OK\n\033[0;34mOK? ERES EL MEJOR Y LO SABES!\033[0m\n");
		else if (stk[0] == 0)
		{
			printf("\nTodos los argumentos son numeros enteros\n");
			ft_orders (stk, ft_stacks(size, stk), size);
			if (stk[0] == -1)
				//printf("OK");
				printf("OK\n\033[0;34mOK? ERES EL MEJOR Y LO SABES!\033[0m\n");
			else
				//printf("KO");
				printf("KO\n\033[0;31mBOOO, ESTA MAL!\033[0m\n\n");
		}
		else
			printf("\n\033[0;31mERROR!\nERROR!\nERROR!\nVAS FATAL!\033[0m\n\n");
		free(stk);
		return (0);
	}
	else
		ft_help();
	return (1);
}

int			ft_orders(long *stk, long *stk2, int dig)
{
	char		cad[4];
	int			i;

	i = 0;
	//ft_printstacks (stk, stk2, dig);
	printf ("Tus ordenes (CTRL+D para terminar):\n");
	while (i > -1)
	{
		i = 0;		
		while (cad[i - 1] != '\n')
			if (!read(0, &cad[i++], 1))
			{
				//ft_printstacks (stk, stk2, dig);
				ft_compare(stk, dig);
				free(stk2);
				return (0);
			}
		if (checkorder(cad) && cad[i - 1] == '\n')
		{
			cad[i - 1] = '\0';
	//		printf ("Exec \033[0;31m%s\033[0m:\n", cad);
			ft_move(stk, stk2, dig, cad);
		}
		else
			printf ("ERRO: No entiendo \033[0;31m%s\033[0m:\n", cad);
	}
	return (0);
}

int		checkorder(char *cad)
{
if (checkchar(cad[0], 1) == 1 && checkchar(cad[1], 2) == 1)
	return (1);
if (checkchar(cad[0], 1) == 1 && checkchar(cad[1], 2) == 2	&& checkchar(cad[2], 3) > 0 && cad[3] == '\n')
	return (1);
return (0);
}

int		checkchar(char c, int pos)
{
if (pos == 1 && (c == 's' || c == 'p' || c == 'r'))
	return (1);
else if ((pos == 2 || pos == 3) && (c == 'a' || c == 'b'))
	return (1);
else if ((pos == 2 || pos == 3) && c == 'r')
	return (2);
return (0);
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