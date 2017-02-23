/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:56:32 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/23 17:08:32 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int	cor_fork(t_env *env, int pc)
{
	signed short arg1;
	t_process *fork;

	CUR_PROC->wait_time = 800;
	arg1 = get_direct_short(ZONE, pc) % IDX_MOD;
	pc = (pc + 2) % MEM_SIZE;

	fork = process_init(CUR_PROC->master, CUR_PROC->master_id);
	fork->carry = CUR_PROC->carry;
	fork->wait_time = 800;
	fork->reg = ft_memcpy(fork->reg, CUR_PROC->reg, REG_NUMBER * REG_SIZE);

	fork->pc = (CUR_PROC->pc + (arg1 % IDX_MOD) + MEM_SIZE) % MEM_SIZE;
	env->display[(CUR_PROC->pc + (arg1 % IDX_MOD) + MEM_SIZE) % MEM_SIZE]->ispc = 1;
	env->process_list = realloc(env->process_list, sizeof(t_process *) * (env->arena->process_amount + 1));
	env->process_list[env->arena->process_amount] = fork;
	env->arena->process_amount++;

	return (pc);
}
