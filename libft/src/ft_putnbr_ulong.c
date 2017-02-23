/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ulong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:22:16 by jde-maga          #+#    #+#             */
/*   Updated: 2016/03/15 13:22:48 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_ulong(unsigned long n)
{
	if (n >= 10)
	{
		ft_putnbr_ulong(n / 10);
		ft_putnbr_ulong(n % 10);
	}
	else
		ft_putchar(48 + n);
}
