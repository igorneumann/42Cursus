/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:23:58 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/17 19:35:50 by ineumann         ###   ########.fr       */
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
	if (argc > 1)
	{
		size = ft_find_args(argc, argv[1]);
		stk = check_values(size, argv, cad);
		if (!(size == 1 || (stk[0] && stk[0] == -1)) && stk[0] == 0)
			ft_orderit(stk, ft_stacks(size, stk), size);
		else if (!(size == 2 || (stk[0] && stk[0] == -1)))
			printf("\n\033[0;31mERROR!\nERROR!\nERROR!\nVAS FATAL!\033[0m\n\n");
		free(stk);
		return (0);
	}
	else
		ft_help();
	return (1);
}

void		ft_orderit(long *stk, long *stk2, int dig)
{
	if (dig == 3)
		printf ("sa");
	else if (dig == 4)
		printf ("%s", ft_ordertree(stk, dig));
	else if (dig > 4 && dig <= 99)
		ft_orderbig(stk, stk2, dig, 0);
	else if (dig > 99 && dig < 200)
		ft_orderhundred(stk, stk2, dig);
	else if (dig >= 200)
		ft_orderhuge(stk, stk2, dig);
//	ft_printstacks (stk, stk2, dig);
	free(stk2);
}

void	ft_help(void)
{
	printf ("\033[0;31m\n  ** FALTAN LOS ARGUMENTOS **\n\n\033[0;34m");
	printf ("Argumentos son numeros enteros separados por espacio\n\n");
	printf ("El programa te dará la mejor combinación de movimientos\n");
	printf ("...al menos la mejor que he sido capaz de llegar.\n\n\033[0m");
}