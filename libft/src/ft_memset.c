/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:27:56 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/25 11:42:38 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*buf;
	unsigned char	bufval;

	buf = ptr;
	bufval = value;
	while (num)
	{
		*buf = bufval;
		num--;
		buf++;
	}
	return (ptr);
}
