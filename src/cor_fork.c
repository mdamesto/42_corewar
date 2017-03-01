/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:56:32 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/01 12:39:52 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_process	*fork_process(t_env *env, int arg1)
{
	t_process *fork;

	fork = process_init(CUR_PROC->master, CUR_PROC->master_id);
	fork->carry = CUR_PROC->carry;
	fork->wait_time = 799;
	fork->pc = MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE);
	if ((long)CUR_PROC->reg == 0x109020000)
	{
		printf("ALERT BIOHAZARD : %d %p\n", CUR_PROC->id, CUR_PROC->reg);
		printf("WE FOUND IT LO : %d %d", CUR_PROC->id, CUR_PROC->reg[0]);
		exit(0);
	}
	for (int i = 0; i != REG_NUMBER; i++)
		fork->reg[i] = CUR_PROC->reg[i];
	return (fork);
}

#define DEBUGMEM  0//(sizeof(t_process *) * (env->arena->process_amount + 1) + 100)

int	cor_fork(t_env *env, int pc)
{
	int arg1;

	//get arg1
	arg1 = get_direct_short(ZONE, pc) % IDX_MOD;
	pc = (pc + 2) % MEM_SIZE;

	//apply fork
	env->process_list = realloc(env->process_list, DEBUGMEM + sizeof(t_process) * (env->arena->process_amount + 1));
	env->process_list[env->arena->process_amount] = fork_process(env, arg1);
	env->arena->process_amount++;

	//update display
	env->display[MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE)]->ispc = 1;

	//set wait time
	CUR_PROC->wait_time = 799;

	if (DEBUG)
		ft_printf("P%4d | fork %d (%d)\n", CUR_PROC->id + 1, arg1, MODFIX(CUR_PROC->pc + (arg1 % IDX_MOD), MEM_SIZE));
	return (pc);
}
