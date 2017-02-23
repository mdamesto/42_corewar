/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:20:06 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 17:25:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*otp;
	char	*buf;

	if ((otp = (char *)malloc(sizeof(*otp) * len + 1)) == NULL || !s)
		return (NULL);
	buf = otp;
	while (start)
	{
		s++;
		start--;
	}
	while (len)
	{
		*otp = *s;
		s++;
		otp++;
		len--;
	}
	*otp = 0;
	return (buf);
}
