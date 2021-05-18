/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:23:58 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/18 21:04:10 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main (int argc, char **argv)
{
	int			count;
	int			size;
	long int	*stk;
	long int	cad[9999];

	count = 0;
	if (argc > 1)
	{
		size = ft_find_args(argc, argv[1]);
		stk = check_values(size, argv, cad);
		if (size != 1 && stk[0] != 4000000000)
			ft_orderit(stk, ft_stacks(size, stk), size);
		else if (size != 2 || stk[0] == 4000000000)
			printf("\n\033[0;31mERROR!\nERROR!\nERROR!\nVAS FATAL!\033[0m\n\n");
		if (stk[0] && stk[0] != 4000000000)
		{
			free(stk);
			return (0);
		}
		if (size < 3)
			ft_help();
	}
	else
		ft_help();
	return (1);
}

void	ft_orderit(long *stk, long *stk2, int dig)
{
	if (dig == 3)
		printf ("sa");
	else if (dig == 4)
		printf ("%s", ft_ordertree(stk, dig));
	else if (dig > 4 && dig <= 23)
		ft_orderhuge(stk, stk2, dig);
	else if (dig > 23 && dig < 99)
		ft_orderhundred(stk, stk2, dig);
	else if (dig >= 23)
		ft_orderhuge(stk, stk2, dig);
	free(stk2);
}

void	ft_help(void)
{
	printf ("\033[0;31m\n  ** FALTAN LOS ARGUMENTOS **\n\n\033[0;34m");
	printf ("Argumentos son numeros enteros separados por espacio\n\n");
	printf ("El programa te dará la mejor combinación de movimientos\n");
	printf ("...al menos la mejor que he sido capaz de llegar.\n\n\033[0m");
}
