/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_ldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:01:06 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/06 16:59:30 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_ldi(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int arg3;
	int kill_op;
	int pos;

	kill_op = 0;
	if (((param & 192) >> 6) == REG_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER)
			kill_op = 1;
		else
		{
			arg1 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
			pc = (pc + 1) % MEM_SIZE;
		}
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
	if (((param & 48) >> 4) == REG_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER)
			kill_op = 1;
		else
		{
			arg2 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else if (((param & 48) >> 4) == DIR_CODE)
	{
		arg2 = get_direct_short(ZONE, pc);
		pc = (pc + 2) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	if (((param & 12) >> 2) == REG_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER)
			kill_op = 1;
		else
		{
			arg3 = ZONE[pc];
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	CUR_PROC->wait_time = 25;
	if (kill_op)
		return (pc);
	pos = MODFIX(CUR_PROC->pc + ((arg1 + arg2) % IDX_MOD), MEM_SIZE);
	CUR_PROC->reg[arg3 - 1] = swap_bytes(get_direct(ZONE, pos));
	if (DEBUG)
	{
		ft_printf("P%4d | ldi %d %d r%d\n", CUR_PROC->id, arg1, arg2, arg3);
		ft_printf("       | -> load from %d + %d = %d\n", arg1, arg2, arg1 + arg2);
	}
	return (pc);
}
