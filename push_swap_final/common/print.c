/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:45:21 by ineumann          #+#    #+#             */
/*   Updated: 2021/05/19 19:53:28 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-checker/checker.h"

void	ft_printstacks (long *i, long *j, int dig)
{
	printg ("\nS:\033[0;32m\tA\t\033[0m|  \033[0;32mB\n");
	while (--dig > 0)
	{
		printg ("\033[0;34m");
		printnum (dig);
		printg ("\033[0m\t");
		printnum (i[dig]);
		if (i[dig] < 9999999 && i[dig] > -999999)
			printg ("\t");
		printg ("|  ");
		printnum (j[dig]);
		printg ("\n");
	}
	if (i[0] != 3000000000 || j[0] != 3000000000)
	{
		printg ("\n\033[0;31mWARNING: Buffer NOT CLEAN:\033[0m\n");
		printnum (i[dig]);
		printg (" - ");
		printnum (i[dig]);
	}
	printg ("\n");
}

void	printg (char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	numcar(long int n)
{
	long int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long int n)
{
	long int	i;
	char		*pnt;
	long int	num;

	num = (long int)n;
	i = numcar(num);
	pnt = malloc((i + 1) * sizeof(char));
	if (!pnt)
		return (0);
	pnt[i] = '\0';
	pnt[0] = '0';
	if (num < 0)
		num *= -1;
	while (i-- > 0)
	{
		pnt[i] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		pnt[0] = '-';
	return (pnt);
}

void	printnum (long num)
{
	char	*str;

	if (num < 2147483647)
	{
		str = ft_itoa(num);
		printg (str);
		free(str);
	}
	else
		printg ("-\t");
}
