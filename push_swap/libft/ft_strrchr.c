/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:20:21 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 15:59:45 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cad;
	char	car;

	i = 0;
	cad = (char*)s;
	car = (char)c;
	while (cad[i] != '\0')
		i++;
	while (cad[i] != car && i > 0)
		i--;
	if (cad[i] == car)
		return (cad + i);
	return (NULL);
}
