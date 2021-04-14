/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:15:49 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 15:49:04 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				y;
	unsigned const char *cad1;
	unsigned const char *cad2;

	i = 0;
	cad1 = (unsigned const char*)haystack;
	cad2 = (unsigned const char*)needle;
	if (cad2[0] == '\0')
		return ((char*)cad1);
	while (cad1[i] != '\0' && i < len)
	{
		y = 0;
		while (cad1[i + y] == cad2[y])
		{
			if ((i + y + 1) > len)
				return (0);
			if (cad2[y + 1] == '\0')
				return ((char*)cad1 + i);
			y++;
		}
		i++;
	}
	return (0);
}
