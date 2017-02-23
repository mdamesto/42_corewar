/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:46:26 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/22 22:44:38 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		get_direct(unsigned char *zone, int pc)
{
	int otp = 0;

	otp = zone[pc] << 24;
	otp += zone[(pc + 1) % MEM_SIZE] << 16;
	otp += zone[(pc + 2) % MEM_SIZE] << 8;
	otp += zone[(pc + 3) % MEM_SIZE];
	return (otp);
}

int		get_indirect(unsigned char *zone, int pc)
{
	int target = 0;
	int otp = 0;

	target = zone[pc] << 8;
	target += zone[(pc + 1) % MEM_SIZE];
	target %= MEM_SIZE;
	target += MEM_SIZE;

	otp = zone[target % MEM_SIZE] << 24;
	otp += zone[(target + 1) % MEM_SIZE] << 16;
	otp += zone[(target + 2) % MEM_SIZE] << 8;
	otp += zone[(target + 3) % MEM_SIZE];
	return (otp);
}

int		get_indirect_idx(unsigned char *zone, int pc, int refpc)
{
	short target = 0;
	int otp = 0;

	target = zone[pc] << 8;
	target += zone[(pc + 1) % MEM_SIZE];
	target += refpc;
	target %= IDX_MOD;
	target += IDX_MOD;

	otp = zone[target % IDX_MOD] << 24;
	otp += zone[(target + 1) % IDX_MOD] << 16;
	otp += zone[(target + 2) % IDX_MOD] << 8;
	otp += zone[(target + 3) % IDX_MOD];

	return (otp);
}

short	get_direct_short(unsigned char *zone, int pc)
{
	int otp = 0;

	otp = zone[pc] << 8;
	otp += zone[(pc + 1) % MEM_SIZE];
	return (otp);
}
