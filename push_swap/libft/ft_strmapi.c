/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:03:38 by ineumann          #+#    #+#             */
/*   Updated: 2019/11/25 15:43:10 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*pnt;
	int				j;

	if (!(s) || !(f))
		return (NULL);
	j = 0;
	i = ft_strlen((char*)s) + 1;
	if (!(pnt = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	while (s[j])
	{
		pnt[j] = f(j, s[j]);
		j++;
	}
	pnt[j] = '\0';
	return (pnt);
}
