/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countmovs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:15:47 by ineumann          #+#    #+#             */
/*   Updated: 2021/04/30 19:44:28 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push-swap/push_swap.h"

int main (void)
{
	char		cad[3];
	int			count;

	count = 0;
	while (read(0, &cad[0], 1))
	{
		if (cad[0] != 's' && cad[0] != 'p' && cad[0] != 'r')
			cad[0] = '\0';
		if (cad[0] != '\0')		
			read(0, &cad[1], 1);
		if (cad[0] == 'r' && cad[1] == 'r')
			read(0, &cad[2], 1);
		else if (cad[1] != 'a' && cad[1] != 'b')
			cad[0] = '\0';
		if (cad[1] == 'r' && (cad[2] != 'a' && cad[2] != 'b'))
			cad[0] = '\0';
		if (cad[0] != '\0')
		{
			count++;
			cad[0] = 1;
		}
	}
	printf("%i movimientos\n", count);
	return (0);
}