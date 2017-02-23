/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:22:30 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/10 16:40:32 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*otp;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((otp = (char *)malloc(sizeof(*otp) * size + 1)) == NULL)
		return (NULL);
	while (*s1)
	{
		*otp = *s1;
		s1++;
		otp++;
	}
	while (*s2)
	{
		*otp = *s2;
		s2++;
		otp++;
	}
	*otp = 0;
	return (otp - size);
}
