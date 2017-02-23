/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:21 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/23 18:30:45 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_ld(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;

	//set wait time
	CUR_PROC->wait_time = 5;

	//get arg1
	if (((param & 192) >> 6) == IND_CODE)
	{
		arg1 = get_indirect_idx(ZONE, pc, CUR_PROC->pc);
		pc = (pc + 2) % MEM_SIZE;
	}
	else if (((param & 192) >> 6) == DIR_CODE)
	{
		arg1 = get_direct(ZONE, pc);
		pc = (pc + 4) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//get arg2
	if (((param & 48) >> 4) == REG_CODE)
	{
		arg2 = ZONE[pc];
		pc = (pc + 1) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//apply load
	CUR_PROC->reg[arg2 - 1] = swap_bytes(arg1);

	//apply carry
	if (!arg1)
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;

	return (pc);
}
