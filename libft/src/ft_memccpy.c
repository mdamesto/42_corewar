/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:49:30 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 17:51:18 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*bufdst;
	char	*bufsrc;

	bufdst = (char *)dst;
	bufsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		bufdst[i] = bufsrc[i];
		if (bufsrc[i] == c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
