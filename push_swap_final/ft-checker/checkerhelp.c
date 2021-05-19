/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerhelp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:32:09 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/19 20:14:06 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_help(void)
{
	printg ("\033[0;31m\n  ** FALTAN LOS ARGUMENTOS **\n\n\033[0;34m");
	printg ("Argumentos son numeros enteros separados por espacio\n\n");
	printg ("Posteriormente el programa pedira los movimientos\n\033[0m");
	printg ("Uno a la vez o todos en la misma linea separados por espacio\n\n");
	printg ("\033[0;34mLos movimientos posible son:\n\n\033[0m");
	printg ("sa: swap a - intercambia los primeros 2 elementos en A. \n");
	printg ("sb: swap b - intercambia los primeros 2 elementos en B. \n");
	printg ("ss: sa y sb al mismo tiempo.\n");
	printg ("pa: empuje a - tome el primer elemento de B y colóquelo en A.\n");
	printg ("pb: empuje b - tome el primer elemento de A y colóquelo en B.\n");
	printg ("ra: rotate a - desplaza hacia arriba los elementos de A en 1.\n");
	printg ("rb: rotate b - desplaza hacia arriba los elementos de B en 1.\n");
	printg ("rr: ra y rb al mismo tiempo.\n");
	printg ("rra: reverse rotate a - desplaza abajo los elementos de A\n");
	printg ("rrb: reverse rotate b - desplaza abajo los elementos de B\n");
	printg ("rrr: rra y rrb al mismo tiempo.\n\n");
	return (0);
}
