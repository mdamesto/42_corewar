/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:15:11 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/23 19:04:03 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_player	*player_init()
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->number = 0;
	player->id = 0;
	player->name = ft_strnew(128);
	player->instructions = malloc(sizeof(unsigned char) * CHAMP_MAX_SIZE);
	player->instructions_size = 0;
	return (player);
}

t_process	*process_init(int master, int master_id)
{
	t_process *process;
	static int id;

	process = malloc(sizeof(t_process));

	process->id = id;
	process->pc = 0;
	process->carry = 0;
	process->master = master;
	process->master_id = master_id;
	process->reg = malloc(REG_NUMBER * REG_SIZE);
	ft_bzero(process->reg, REG_NUMBER * REG_SIZE);
	process->wait_time = 0;
	id++;
	return (process);
}

t_arena *arena_init()
{
	t_arena *arena = malloc(sizeof(t_arena));
	int i;

	i = 0;
	arena->current_cycle = 0;
	arena->process_amount = 0;
	arena->player_amount = 0;
	arena->current_process = 0;
	arena->zone = malloc(sizeof(unsigned char *) * MEM_SIZE);
	arena->alive_check = malloc(sizeof(int) * MAX_PLAYERS + 1);
	while (i != MAX_PLAYERS)
	{
		arena->alive_check[i] = 0;
		i++;
	}

	return (arena);
}

t_env *env_init()
{
	t_env *env;
	int i;

	i = 0;
	env = malloc(sizeof(t_env));
	env->arena = arena_init();
	env->player_list = malloc(sizeof(t_player *) * MAX_PLAYERS + 1);
	env->process_list = malloc(sizeof(t_process *) * MAX_PLAYERS + 1);
	env->display = malloc(sizeof(t_display *) * MEM_SIZE);
	while (i != MEM_SIZE)
	{
		env->display[i] = display_init();
		i++;
	}

	return (env);
}

t_display *display_init()
{
	t_display *display;

	display = malloc(sizeof(t_display));
	display->value = 0;
	display->champion = 0;
	display->recent_display = 0;
	display->ispc = 0;

	return (display);
}
