/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:04:06 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 15:33:33 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int s2size;

	i = 0;
	j = 0;
	s2size = 0;
	while (s2[s2size])
		s2size++;
	if (!s2size)
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + j] == s2[j])
		{
			if (j == s2size - 1)
				return ((char *)s1 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
