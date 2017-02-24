/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:03 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/24 18:59:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_live(t_env *env, int pc)
{
	int arg1;

	//get arg1
	arg1 = get_direct(ZONE, pc);
	pc = (pc + 4) % MEM_SIZE;

	//apply live
	/* allan add livecheck */

	//set wait time
	CUR_PROC->wait_time = 10;

	if (DEBUG)
		ft_printf("P%4d | live %d\n", CUR_PROC->id + 1, arg1);
	return (pc);
}
