/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_llong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:28:48 by jde-maga          #+#    #+#             */
/*   Updated: 2016/03/15 14:30:52 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_llong(long long n)
{
	int llongmin;

	llongmin = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == LLONG_MIN)
		{
			n++;
			llongmin = 1;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_llong(n / 10);
		ft_putnbr_llong((n % 10) + llongmin);
	}
	else
		ft_putchar(48 + n);
}
