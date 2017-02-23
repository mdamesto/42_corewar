/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:45:05 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/01 15:24:55 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*buf;
	const unsigned char	*bufsrc;

	buf = dest;
	bufsrc = src;
	while (n)
	{
		*buf = *bufsrc;
		buf++;
		bufsrc++;
		n--;
	}
	return (dest);
}
