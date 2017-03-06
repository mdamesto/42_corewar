/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:20:20 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/06 16:46:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_add(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int arg3;
	int value;
	int kill_op;

	kill_op = 0;
	if (((param & 192) >> 6) == REG_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER)
			kill_op = 1;
		else
		{
			arg1 = ZONE[pc];
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);
	if (((param & 48) >> 4) == REG_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER)
			kill_op = 1;
		else
		{
			arg2 = ZONE[pc];
			pc = (pc + 1) % MEM_SIZE;
		}
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
	CUR_PROC->wait_time = 10;
	if (kill_op)
		return (pc);
	value = swap_bytes(swap_bytes(CUR_PROC->reg[arg1 - 1]) + swap_bytes(CUR_PROC->reg[arg2 - 1]));
	CUR_PROC->reg[arg3 - 1] = value;
	if (!value)
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;
	if (DEBUG)
		ft_printf("P%4d | add r%d r%d r%d\n", CUR_PROC->id + 1, arg1, arg2, arg3);
	return (pc);
}
