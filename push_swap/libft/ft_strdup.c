/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:36:36 by ineumann          #+#    #+#             */
/*   Updated: 2020/07/17 18:45:55 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*pnt;

	i = 0;
	while (s[i] != '\0')
		i++;
	i += 1;
	pnt = malloc(i * sizeof(char));
	if (pnt == NULL)
		return (NULL);
	while (i-- > 0)
		pnt[i] = s[i];
	return (pnt);
}
