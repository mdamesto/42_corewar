/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:12:32 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/25 16:39:07 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*buf;
	unsigned char		bufc;

	buf = s;
	bufc = c;
	while (n)
	{
		if (*buf == bufc)
			return ((void *)buf);
		buf++;
		n--;
	}
	return (NULL);
}
