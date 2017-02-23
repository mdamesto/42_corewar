/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:50:43 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/25 12:57:14 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	const char	*bufs;

	bufs = s;
	while (*bufs)
	{
		if (*bufs == c)
			return ((char *)bufs);
		bufs++;
	}
	if (!c)
		return ((char *)bufs);
	return (NULL);
}
