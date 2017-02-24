/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_lfork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:17:58 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/23 17:07:00 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_process	*fork_process(t_env *env, int pc, int arg1)
{
	t_process *fork;
	fork = process_init(CUR_PROC->master, CUR_PROC->master_id);

	fork->carry = CUR_PROC->carry;
	fork->wait_time = 1000;
	fork->reg = ft_memcpy(fork->reg, CUR_PROC->reg, REG_NUMBER * REG_SIZE);
	fork->pc = MODFIX(CUR_PROC->pc + arg1, MEM_SIZE);

	return (fork);
}

int		cor_lfork(t_env *env, int pc)
{
	int arg1;

	//set wait time
	CUR_PROC->wait_time = 1000;

	//get arg1
	if (((param & 192) >> 6) == DIR_CODE)
	{
		arg1 = get_direct_short(ZONE, pc) % IDX_MOD;
		pc = (pc + 2) % MEM_SIZE;
	}
	else
		return ((CUR_PROC->pc + 1) % MEM_SIZE);

	//apply lfork
	env->process_list = realloc(env->process_list, sizeof(t_process *) * (env->arena->process_amount + 1));
	env->process_list[env->arena->process_amount] = fork_process(env, pc, arg1);
	env->arena_process_amount++;

	//update display
	env->display[MODFIX(CUR_PROC->pc + arg1, MEM_SIZE)]->ispc = 1;
	
	return (pc);
}
