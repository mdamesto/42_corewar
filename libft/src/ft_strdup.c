/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:29:45 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/08 15:46:09 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*otp;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if ((otp = (char *)malloc(sizeof(*otp) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		otp[i] = s1[i];
		i++;
	}
	otp[i] = 0;
	return (otp);
}
