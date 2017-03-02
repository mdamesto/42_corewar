/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:23:10 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/02 17:20:08 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_aff(t_env *env, int param, int pc)
{
	int arg1;
	unsigned char buf;
	int kill_op = 0;
	(void)param;

	//get arg1
	if (((param & 192) >> 6) == DIR_CODE)
	{
		if (ZONE[pc] - 1 < 0 || ZONE[pc] - 1 >= REG_NUMBER) //invalid reg, quit
			kill_op = 1;
		else
		{
			arg1 = CUR_PROC->reg[ZONE[pc] - 1];
			pc = (pc + 1) % MEM_SIZE;
		}
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//set wait time
	CUR_PROC->wait_time = 2;
	if (kill_op)
		return (pc);

	//apply aff
	buf = MODFIX(arg1 % 256, 256);
	write(1, &buf, 1);

	return (pc);
}
