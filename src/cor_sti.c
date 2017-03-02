/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:34:37 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/02 20:09:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_sti(t_env *env, int param, int pc)
{
	int arg1 = 0;
	int arg2 = 0;
	int arg3 = 0;
	int kill_op = 0;

	int debugs = 0;

	//get arg1
	if (((param & 192) >> 6) == REG_CODE)
	{
		debugs = ZONE[pc];
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER) //invalid reg, quit
			kill_op = 1;
		else
		{
			arg1 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//get arg2
	if (((param & 48) >> 4) == REG_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER) //invalid reg, quit
			kill_op = 1;
		else
		{
			arg2 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else if (((param & 48) >> 4) == IND_CODE)
	{
		arg2 = get_indirect_idx(ZONE, pc, CUR_PROC->pc);
		pc = (pc + 2) % MEM_SIZE;
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
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER) //invalid reg, quit
			kill_op = 1;
		else
		{
			arg3 = swap_bytes(CUR_PROC->reg[ZONE[pc] - 1]);
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else if (((param & 12) >> 2) == DIR_CODE)
	{
		arg3 = get_direct_short(ZONE, pc);
		pc = (pc + 2) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//set wait time
	CUR_PROC->wait_time = 25;

	if (kill_op)
		return (pc);

	//apply sti
	int pos = MODFIX(CUR_PROC->pc + ((arg2 + arg3) % IDX_MOD), MEM_SIZE);
	ZONE[pos % MEM_SIZE] = (arg1 & 0xff000000) >> 24;
	ZONE[(pos + 1) % MEM_SIZE] = (arg1 & 0x00ff0000) >> 16;
	ZONE[(pos + 2) % MEM_SIZE] = (arg1 & 0x0000ff00) >> 8;
	ZONE[(pos + 3) % MEM_SIZE] = (arg1 & 0x000000ff);

	//update display
	env->display[pos % MEM_SIZE]->value = (arg1 & 0xff000000) >> 24;
	env->display[(pos + 1) % MEM_SIZE]->value = (arg1 & 0x00ff0000) >> 16;
	env->display[(pos + 2) % MEM_SIZE]->value = (arg1 & 0x0000ff00) >> 8;
	env->display[(pos + 3) % MEM_SIZE]->value = (arg1 & 0x000000ff);

	env->display[pos % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(pos + 1) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(pos + 2) % MEM_SIZE]->champion = CUR_PROC->master_id;
	env->display[(pos + 3) % MEM_SIZE]->champion = CUR_PROC->master_id;

	env->display[pos % MEM_SIZE]->recent_display = 10;
	env->display[(pos + 1) % MEM_SIZE]->recent_display = 10;
	env->display[(pos + 2) % MEM_SIZE]->recent_display = 10;
	env->display[(pos + 3) % MEM_SIZE]->recent_display = 10;

	if (DEBUG)
	{
		printf("P%4d | sti r%d %d %d\n", CUR_PROC->id, debugs, arg2, arg3);
		printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", arg2, arg3, arg2+arg3, CUR_PROC->pc);
	}
	return (pc);
}
