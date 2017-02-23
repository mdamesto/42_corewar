/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:29:46 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 17:31:02 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_strtrim_size(char *s)
{
	int i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i])
		i++;
	while (!s[i] || s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*otp;
	char	*buf;
	int		size;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	size = ft_strtrim_size((char *)s);
	if ((otp = (char *)malloc(sizeof(*otp) * size + 1)) == NULL)
		return (NULL);
	buf = otp;
	while (size)
	{
		*otp = *s;
		s++;
		otp++;
		size--;
	}
	*otp = 0;
	return (buf);
}
