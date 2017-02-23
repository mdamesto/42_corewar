/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:07:46 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 16:17:07 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static const char	*ft_strlcat_write(size_t bufsize, char *bufdst,
									const char *bufsrc)
{
	while (*bufsrc)
	{
		if (bufsize != 1)
		{
			*bufdst++ = *bufsrc;
			bufsize--;
		}
		bufsrc++;
	}
	*bufdst = 0;
	return (bufsrc);
}

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*bufdst;
	const char	*bufsrc;
	size_t		dstsize;
	size_t		bufsize;

	bufdst = dst;
	bufsrc = src;
	bufsize = size;
	while (bufsize && *bufdst)
	{
		bufdst++;
		bufsize--;
	}
	dstsize = bufdst - dst;
	bufsize = size - dstsize;
	if (!bufsize)
		return (dstsize + ft_strlen(src));
	bufsrc = ft_strlcat_write(bufsize, bufdst, bufsrc);
	return (dstsize + (bufsrc - src));
}
