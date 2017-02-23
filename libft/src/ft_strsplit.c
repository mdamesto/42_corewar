/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:20:24 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 17:30:35 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_strsplit_arraysize(char const *s, char c)
{
	int otp;
	int i;

	otp = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			otp++;
		i++;
	}
	return (otp);
}

static int		ft_strsplit_wordsize(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char		*ft_strsplit_getword(char const *s, char c)
{
	int		i;
	char	*otp;

	i = 0;
	if ((otp = (char *)malloc(sizeof(*otp) * ft_strsplit_wordsize(s, c) + 1))
		== NULL)
		return (NULL);
	while (s[i] != c && s[i])
	{
		otp[i] = s[i];
		i++;
	}
	otp[i] = 0;
	return (otp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**otp;
	int		index;
	int		i;

	i = 0;
	index = 0;
	if (!s || (otp = (char **)malloc(sizeof(**otp) * ft_strsplit_arraysize(s, c)
	+ 40)) == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			otp[index] = ft_strsplit_getword(&s[i], c);
			index++;
			i += ft_strsplit_wordsize(&s[i], c) - 1;
		}
		i++;
	}
	otp[index] = 0;
	return (otp);
}
