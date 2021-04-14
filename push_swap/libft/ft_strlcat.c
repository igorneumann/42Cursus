/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:35:24 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 17:03:11 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	while (dst[i] && i < size)
		i++;
	while (src[y] && (y + i + 1) < size)
	{
		dst[i + y] = src[y];
		y++;
	}
	if (i < size)
		dst[i + y] = '\0';
	return (i + ft_strlen(src));
}
