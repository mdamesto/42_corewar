/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:23:10 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/20 19:06:00 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cor_aff(t_env *env, int param, int pc)
{
	int arg1;
	unsigned char buf;

	CUR_PROC->wait_time = 2;

	arg1 = CUR_PROC->reg[ZONE[pc]];

	buf = arg1 % 256;
	write(1, &buf, 1);
	pc = (pc + 1) % MEM_SIZE;
	(void)param;
	return (pc);
}
