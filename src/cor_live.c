/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:03 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/01 09:48:05 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void		apply_livecheck(t_env *env, int arg1)
{
	int i = 0;

	while (env->player_list[i])
	{
		if (env->player_list[i]->number == arg1)
		{
			//		ft_printf("un processus dit que le joueur %d(%s) est en vie\n", env->player_list[i]->number, env->player_list[i]->name);
			env->player_list[i]->isalive = 1;
		}
		i++;
	}
}

int		cor_live(t_env *env, int pc)
{
	int arg1;

	//get arg1
	arg1 = get_direct(ZONE, pc);
	pc = (pc + 4) % MEM_SIZE;

	//apply live
	apply_livecheck(env, arg1);
	env->arena->live_call++;

	//set wait time
	CUR_PROC->wait_time = 10;

	if (DEBUG)
		ft_printf("P%4d | live %d\n", CUR_PROC->id + 1, arg1);
	return (pc);
}
