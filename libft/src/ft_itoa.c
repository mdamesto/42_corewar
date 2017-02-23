/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoav2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:39:15 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/16 12:57:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_itoa_size(long n)
{
	int otp;

	otp = 1;
	while (n >= 10)
	{
		n /= 10;
		otp++;
	}
	return (otp);
}

static long		ft_itoa_timesten(int size)
{
	long c;

	c = 1;
	while (size)
	{
		c *= 10;
		size--;
	}
	return (c / 10);
}

char			*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*otp;
	long	bufn;

	bufn = n;
	i = 0;
	if (bufn < 0)
	{
		bufn = -bufn;
		i++;
	}
	size = ft_itoa_size(bufn);
	if ((otp = (char *)malloc(sizeof(char) * size + 1 + i)) == NULL)
		return (NULL);
	if (i)
		otp[0] = '-';
	while (size)
	{
		otp[i] = (bufn / ft_itoa_timesten(size)) % 10 + 48;
		size--;
		i++;
	}
	otp[i] = 0;
	return (otp);
}
