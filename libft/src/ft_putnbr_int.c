/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:06:54 by jde-maga          #+#    #+#             */
/*   Updated: 2016/03/15 14:25:21 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_int(int n)
{
	int intmin;

	intmin = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == INT_MIN)
		{
			n++;
			intmin = 1;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_int(n / 10);
		ft_putnbr_int((n % 10) + intmin);
	}
	else
		ft_putchar(48 + n);
}
