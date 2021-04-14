/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:08:19 by igorneumann       #+#    #+#             */
/*   Updated: 2019/11/25 15:44:32 by ineumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*pnt;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(pnt = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (!(start > ft_strlen(s)))
	{
		while (j < len)
		{
			pnt[j] = s[i + start];
			i++;
			j++;
		}
	}
	pnt[j] = '\0';
	return (pnt);
}
