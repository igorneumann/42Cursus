/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:17:32 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 15:46:56 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t				i;
	unsigned char		*cad1;
	unsigned char		*cad2;

	cad1 = (unsigned char*)dest;
	cad2 = (unsigned char*)src;
	i = 0;
	while (i < size)
	{
		if (cad2[i] == (unsigned char)c)
		{
			cad1[i] = cad2[i];
			return (cad1 + i + 1);
		}
		cad1[i] = cad2[i];
		i++;
	}
	return (0);
}
