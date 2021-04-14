/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:03:07 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 17:10:15 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cad;
	char	car;

	i = 0;
	cad = (char*)s;
	car = (char)c;
	while (cad[i] != car && cad[i] != '\0')
		i++;
	if (cad[i] == car)
		return (cad + i);
	return (0);
}
