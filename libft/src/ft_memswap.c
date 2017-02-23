/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:16:00 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/01 15:50:06 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_memswap(void *a, void *b, size_t size, size_t start)
{
	unsigned char	*bufa;
	unsigned char	*bufb;
	unsigned char	buffer;
	size_t			i;

	if (a && b)
	{
		bufa = a;
		bufb = b;
		while (start)
		{
			bufa++;
			bufb++;
			start--;
		}
		i = 0;
		while (i < size)
		{
			buffer = bufa[i];
			bufa[i] = bufb[i];
			bufb[i] = buffer;
			i++;
		}
	}
}
