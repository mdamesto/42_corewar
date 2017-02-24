/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:29:29 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/24 18:55:37 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_sub(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int arg3;
	int value;

	//get arg1
	if (((param & 192) >> 6) == REG_CODE)
	{
		arg1 = ZONE[pc];
		pc = (pc + 1) % MEM_SIZE;
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

	//get arg3
	if (((param & 12) >> 2) == REG_CODE)
	{
		arg3 = ZONE[pc];
		pc = (pc + 1) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//apply sub
	value = swap_bytes(swap_bytes(CUR_PROC->reg[arg1 - 1]) - swap_bytes(CUR_PROC->reg[arg2 - 1]));
	CUR_PROC->reg[arg3 - 1] = value;

	//set carry
	if (!value)
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;

	//set wait time
	CUR_PROC->wait_time = 10;

	return (pc);
}
