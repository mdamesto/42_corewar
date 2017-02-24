/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:03 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/23 18:19:50 by jde-maga         ###   ########.fr       */
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

	return (pc);
}
