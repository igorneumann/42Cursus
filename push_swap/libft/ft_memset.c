/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:31:38 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 15:38:38 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t				i;
	unsigned char		*cad;

	i = 0;
	cad = (unsigned char*)str;
	while (i < len)
		cad[i++] = (unsigned char)c;
	return (cad);
}
