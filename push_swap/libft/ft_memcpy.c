/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:22:56 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 16:59:27 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char		*cad1;
	unsigned char		*cad2;

	cad1 = (unsigned char*)str1;
	cad2 = (unsigned char*)str2;
	if (!n || str1 == str2)
		return (str1);
	while (n--)
		*cad1++ = *cad2++;
	return (str1);
}
