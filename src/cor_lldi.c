/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_lldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:16:39 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/22 23:10:06 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_lldi(t_env *env, int param, int pc)
{
	int arg1 = 0;
	int arg2 = 0;
	int arg3 = 0;

	//get arg1
	if (((param & 192) >> 6) == REG_CODE)
	{
		arg1 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
		pc = (pc + 1) % MEM_SIZE;
	}
	else if (((param & 192) >> 6) == IND_CODE)
	{
		arg1 = get_indirect_idx(ZONE, pc, CUR_PROC->pc);
		pc = (pc + 2) % MEM_SIZE;
	}
	else if (((param & 192) >> 6) == DIR_CODE)
	{
		arg1 = get_direct_short(ZONE, pc);
		pc = (pc + 2) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//get arg2
	if (((param & 48) >> 4) == REG_CODE)
	{
		arg2 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
		pc = (pc + 1) % MEM_SIZE;
	}
	else if (((param & 48) >> 4) == DIR_CODE)
	{
		arg2 = get_direct_short(ZONE, pc);
		pc = (pc + 2) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//get arg3
	if (((param & 12) >> 2) == REG_CODE)
	{
		arg3 = ZONE[pc];
		pc = (pc + 1) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//apply lldi
	int pos = MODFIX(CUR_PROC->pc + arg1 + arg2, MEM_SIZE);
	CUR_PROC->reg[arg3 - 1] = swap_bytes(get_direct(ZONE, pos));

	//set wait time
	CUR_PROC->wait_time = 50;

	return (pc);
}