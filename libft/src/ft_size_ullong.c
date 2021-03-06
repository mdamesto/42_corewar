/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_ullong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:10:11 by jde-maga          #+#    #+#             */
/*   Updated: 2016/03/15 13:13:42 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_size_ullong(unsigned long long u)
{
	int	i;

	i = 1;
	while (u >= 10)
	{
		u /= 10;
		i++;
	}
	return (i);
}
