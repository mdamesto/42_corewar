/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:57:39 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/27 17:03:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_strrchr(const char *s, int c)
{
	const char	*bufs;
	char		*otp;

	otp = NULL;
	bufs = s;
	while (*bufs)
	{
		if (*bufs == c)
			otp = (char *)bufs;
		bufs++;
	}
	if (!c)
		otp = (char *)bufs;
	return (otp);
}
