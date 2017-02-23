/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:00:41 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/10 18:10:22 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *otp;

	if ((otp = (unsigned char *)malloc(sizeof(unsigned char) * size)) == NULL)
		return (NULL);
	if (size == 0)
		return (NULL);
	ft_bzero(otp, size);
	return ((void *)otp);
}
