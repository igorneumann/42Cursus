/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:07:31 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/21 17:16:03 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main (int argc, char **argv)
{
	int			count;
	int			size;
	long int	*stk;
	long int	cad[999];

	if (argc <= 1 && (ft_help() == 0))
		return (1);
	count = 0;
	size = ft_find_args(argc, argv[1]);
	if (size != argc)
		stk = check_args(size, argv[1], cad);
	else
		stk = check_values(size, argv, cad);
	if (stk[0] && stk[0] == -1)
		printg("\033[0;32mOK\n\033[0;34mOK? ERES EL MEJOR Y LO SABES!\033[0m\n");
	else if (stk[0] == 0)
		ft_checkok(size, stk);
	else
		printg("\n\033[0;31mERROR!\nERROR!\nERROR!\nVAS FATAL!\033[0m\n\n");
	if (stk[0] && stk[0] != 4000000000)
		free(stk);
	return (0);
}

void	ft_checkok(int size, long int *stk)
{
	printg("\nTodos los argumentos son numeros enteros\n\n");
	printg ("\033[0;34mTus ordenes \033[0m(CTRL+D para terminar):\n");
	ft_orders (stk, ft_stacks(size, stk), size, 0);
	if (stk[0] == -1)
		printg("\033[0;32mOK\033[0m\n");
	else
		printg("\033[0;31mKO\033[0m\n");
}

int	ft_orders(long *stk, long *stk2, int dig, int i)
{
	char		cad[4];

	while (i > -1)
	{
		i = 0;
		while (i == 0 || cad[i - 1] != '\n')
		{
			if (!read(0, &cad[i++], 1))
			{
				free (stk2);
				return ((int)ft_compare (stk, dig));
			}
		}
		if (checkorder(cad) && cad[i - 1] == '\n')
		{
			cad[i - 1] = '\0';
			ft_move(stk, stk2, dig, cad);
		}
		else
		{
			printg ("ERROR: No entiendo");
			printg (cad);
		}
	}
	return (0);
}

int	checkorder(char *cad)
{
	if ((checkchar(cad[0], 1) == 1 && checkchar(cad[1], 2) == 1)
		|| (cad[0] == 'p' && checkchar(cad[1], 2) == 2 && cad[2] == '+')
		|| ((checkchar(cad[0], 1) == 1 && checkchar(cad[1], 2) == 2
				&& checkchar(cad[2], 3) > 0 && cad[3] == '\n')))
		return (1);
	return (0);
}

int	checkchar(char c, int pos)
{
	if (pos == 1 && (c == 's' || c == 'p' || c == 'r'))
		return (1);
	else if ((pos == 2 || pos == 3) && (c == 'a' || c == 'b'))
		return (1);
	else if ((pos == 2 || pos == 3) && c == 'r')
		return (2);
	return (0);
}
