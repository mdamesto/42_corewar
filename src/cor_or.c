/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:49:34 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/02 17:12:12 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_or(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int arg3;
	int kill_op = 0;


	//get arg1
	if (((param & 192) >> 6) == REG_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER) //invalid reg, quit
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
		arg1 = get_direct(ZONE, pc);
		pc = (pc + 4) % MEM_SIZE;
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
		arg2 = get_direct(ZONE, pc);
		pc = (pc + 4) % MEM_SIZE;
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
			arg3 = ZONE[pc];
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//set wait time
	CUR_PROC->wait_time = 6;

	if (kill_op)
		return (pc);

	//apply or
	CUR_PROC->reg[arg3 - 1] = swap_bytes(arg1 | arg2);

	//set carry
	if (!(arg1 | arg2))
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;

	return (pc);
}
