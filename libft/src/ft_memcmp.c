/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:23:57 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/25 12:28:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *bufs1;
	const unsigned char *bufs2;

	bufs1 = s1;
	bufs2 = s2;
	while (n)
	{
		if (*bufs1 != *bufs2)
			return (*bufs1 - *bufs2);
		bufs1++;
		bufs2++;
		n--;
	}
	return (0);
}
