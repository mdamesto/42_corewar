/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:31:09 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/16 15:44:11 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		swap_bytes(int arg)
{
	int byte1 = (arg & 0xFF000000) >> 24;
	int byte2 = (arg & 0x00FF0000) >> 16;
	int byte3 = (arg & 0x0000FF00) >> 8;
	int byte4 = (arg & 0x000000FF);
	int otp;

	otp = byte1;
	otp += byte2 << 8;
	otp += byte3 << 16;
	otp += byte4 << 24;

	return (otp);
}
