/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ullong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:13:57 by jde-maga          #+#    #+#             */
/*   Updated: 2016/03/15 13:16:20 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_ullong(unsigned long long n)
{
	if (n >= 10)
	{
		ft_putnbr_ullong(n / 10);
		ft_putnbr_ullong(n % 10);
	}
	else
		ft_putchar(48 + n);
}
