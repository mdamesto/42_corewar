/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:06:08 by jde-maga          #+#    #+#             */
/*   Updated: 2016/03/15 14:17:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_long(long n)
{
	int longmin;

	longmin = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == LONG_MIN)
		{
			n++;
			longmin = 1;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_long(n / 10);
		ft_putnbr_long((n % 10) + longmin);
	}
	else
		ft_putchar(48 + n);
}
