/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:52:57 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/24 18:56:28 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_zjmp(t_env *env, int pc)
{
	int arg1;

	//get arg1;
	arg1 = get_direct_short(ZONE, pc);
	pc = (pc + 2) % MEM_SIZE;

	//apply zjmp
	if (!CUR_PROC->carry)
	{
		if (DEBUG)
			ft_printf("P%4d | zjmp %d FAILED\n", CUR_PROC->id, arg1);
		return (pc);
	}
	else
		pc = MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE);

	//set wait time
	CUR_PROC->wait_time = 20;

	if (DEBUG)
		ft_printf("P%4d | zjmp %d OK\n", CUR_PROC->id + 1, arg1 % IDX_MOD);
	return (pc);
}
