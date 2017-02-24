/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:52:57 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/20 17:27:30 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_zjmp(t_env *env, int pc)
{
	int arg1;

	//set wait time
	CUR_PROC->wait_time = 20;

	//get arg1;
	if (((param & 192) >> 6) == DIR_CODE)
	{
		arg1 = get_direct_short(ZONE, pc);
		pc = (pc + 2) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//apply zjmp
	if (!CUR_PROC->carry)
		return (pc);
	else
		pc = MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE);

	return (pc);
}
