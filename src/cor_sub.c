/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:29:29 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/20 14:13:08 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_sub(t_env *env, int param, int pc)
{
	int arg1;
	int arg2;
	int arg3;
	int value;

	CUR_PROC->wait_time = 10;
	arg1 = ZONE[pc];
	pc = (pc + 1) % MEM_SIZE;
	arg2 = ZONE[pc];
	pc = (pc + 1) % MEM_SIZE;
	arg3 = ZONE[pc];
	pc = (pc + 1) % MEM_SIZE;
	value = swap_bytes(swap_bytes(CUR_PROC->reg[arg1 - 1]) - swap_bytes(CUR_PROC->reg[arg2 - 1]));
	CUR_PROC->reg[arg3 - 1] = swap_bytes(value);

	if (!value)
		CUR_PROC->carry = 1;
	else
		CUR_PROC->carry = 0;

	(void)param;
	return (pc);
}
