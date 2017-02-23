/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:49:34 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/22 21:19:49 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_or(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;

	CUR_PROC->wait_time = 6;
	if ((param & 192) == 64)
		arg1 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
	else if (((param & 192) >> 6) == IND_CODE)
	{
		arg1 = get_indirect_idx(ZONE, pc, CUR_PROC->pc);
		pc = (pc + 1) % MEM_SIZE;
	}
	else
	{
		arg1 = get_direct(ZONE, pc);
		pc = (pc + 3) % MEM_SIZE;
	}
	pc = (pc + 1) % MEM_SIZE;
	if (((param & 48) >> 4) == REG_CODE)
		arg2 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
	else if (((param & 48) >> 4) == IND_CODE)
	{
		arg2 = get_indirect_idx(ZONE, pc, CUR_PROC->pc);
		pc = (pc + 1) % MEM_SIZE;
	}
	else
	{
		arg2 = get_direct(ZONE, pc);
		pc = (pc + 3) % MEM_SIZE;
	}
	pc = (pc + 1) % MEM_SIZE;
	CUR_PROC->reg[ZONE[pc] - 1] = arg1 | arg2;
	pc = (pc + 1) % MEM_SIZE;

	if (!(arg1 | arg2))
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;
	return (pc);
}
