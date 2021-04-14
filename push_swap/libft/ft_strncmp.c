/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:24:18 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 15:43:21 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	while ((n - 1) > 0)
	{
		if (s1[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - s2[i]);
}
