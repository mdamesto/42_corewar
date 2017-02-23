/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:02:55 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 17:53:17 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*otp;
	size_t	i;

	if ((otp = (char *)malloc(sizeof(*otp) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		otp[i] = 0;
		i++;
	}
	otp[i] = 0;
	return (otp);
}
