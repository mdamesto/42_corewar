/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:53:31 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/16 13:56:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *bufdst;
	char *bufsrc;

	bufdst = (char *)dst;
	bufsrc = (char *)src;
	if (dst > src)
	{
		bufdst += n;
		bufsrc += n;
		while (n)
		{
			bufdst--;
			bufsrc--;
			*bufdst = *bufsrc;
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
