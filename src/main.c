/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:54:36 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/07 18:07:12 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	create_starting_process(t_env *env)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (env->player_list[i])
	{
		env->process_list[i]->pc = j;
		env->display[j]->ispc = 1;
		env->player_list[i]->id = i + 1;
		while (k != env->player_list[i]->instructions_size)
		{
			env->arena->zone[j] = env->player_list[i]->instructions[k];
			env->display[j]->value = env->arena->zone[j];
			env->display[j]->champion = i + 1;
			j++;
			k++;
		}
		i++;
		j = (MEM_SIZE / env->arena->player_amount) * i;
		k = 0;
	}
}

void	inject_players(t_env *env)
{
	int i;

	i = 0;
	while (env->player_list[i])
	{
		env->process_list[i] = process_init(env->player_list[i]->number, i + 1);
		env->process_list[i]->reg[0] = swap_bytes(env->player_list[i]->number);
		env->arena->process_amount++;
		i++;
	}
	create_starting_process(env);
}

int		operation(t_env *env, int opcode, int param, int pc)
{
	if (opcode == 1)
		pc = cor_live(env, pc);
	else if (opcode == 2)
		pc = cor_ld(env, param, pc);
	else if (opcode == 3)
		pc = cor_st(env, param, pc);
	else if (opcode == 4)
		pc = cor_add(env, param, pc);
	else if (opcode == 5)
		pc = cor_sub(env, param, pc);
	else if (opcode == 6)
		pc = cor_and(env, param, pc);
	else if (opcode == 7)
		pc = cor_or(env, param, pc);
	else if (opcode == 8)
		pc = cor_xor(env, param, pc);
	else if (opcode == 9)
		pc = cor_zjmp(env, pc);
	else if (opcode == 10)
		pc = cor_ldi(env, param, pc);
	else if (opcode == 11)
		pc = cor_sti(env, param, pc);
	else if (opcode == 12)
		pc = cor_fork(env, pc);
	else if (opcode == 13)
		pc = cor_lld(env, param, pc);
	else if (opcode == 14)
		pc = cor_lldi(env, param, pc);
	else if (opcode == 15)
		pc = cor_lfork(env, pc);
	else if (opcode == 16)
		pc = cor_aff(env, param, pc);
	else
		pc = (CUR_PROC->pc + 1) % MEM_SIZE;
	return (pc);
}

void	live_check(t_env *env)
{
	int i;
	int alive;

	i = 0;
	alive = env->arena->player_amount;
	while (env->player_list[i])
	{
		if (!env->player_list[i]->isalive)
			alive--;
		i++;
	}
	i = 0;
	if (!alive)
	{
		ft_printf("tout les joueurs sont morts !\n");
		exit(0);
	}
	else if (alive == 1)
	{
		while (env->player_list[i])
		{
			if (!env->player_list[i]->isalive)
			{
				ft_printf("le joueur %d(%s) a gagne\n",
						env->player_list[i]->number, env->player_list[i]->name);
				exit(0);
			}
			i++;
		}
	}
	else
		while (env->player_list[i])
		{
			env->player_list[i]->isalive = 0;
			i++;
		}
}

void	end_cycle(t_env *env)
{
	if (DISPLAY)
		display(env->display, env);
	env->arena->current_cycle++;
	env->arena->live_cycle++;
	if (env->arena->live_cycle >= env->arena->cycle_to_die)
	{
		env->arena->max_checks++;
		if (env->arena->live_call >= NBR_LIVE ||
			env->arena->max_checks >= MAX_CHECKS)
		{
			env->arena->cycle_to_die -= CYCLE_DELTA;
			env->arena->max_checks = 0;
		}
		live_check(env);
		env->arena->live_call = 0;
		env->arena->live_cycle = 0;
		if (env->arena->cycle_to_die < 0)
			env->arena->cycle_to_die = 0;
	}
}

void	process_turn(t_env *env)
{
	int opcode;
	int	param;
	int pc;

	opcode = 0;
	param = 0;
	while (1)
	{
		env->arena->current_process = env->arena->process_amount - 1;
		while (env->arena->current_process >= 0)
		{
			if (CUR_PROC->wait_time)
				CUR_PROC->wait_time--;
			if (!CUR_PROC->wait_time)
			{
				pc = CUR_PROC->pc;
				opcode = ZONE[pc];
				pc = (pc + 1) % MEM_SIZE;
				if (!(opcode == 1 || opcode == 9 ||
					opcode == 12 || opcode == 15))
				{
					param = ZONE[pc % MEM_SIZE];
					pc = (pc + 1) % MEM_SIZE;
				}
				env->display[CUR_PROC->pc]->ispc = 0;
				CUR_PROC->pc = operation(env, opcode, param, pc);
				env->display[CUR_PROC->pc]->ispc = 1;
			}
			env->arena->current_process--;
		}
		end_cycle(env);
	}
}

int		main(int argc, char **argv)
{
	t_env	*env;
	int		j;

	env = env_init();
	if (argc == 1)
	{
		ft_printf("no commmands\n");
		return (0);
	}
	j = arg_parser(argc, argv, env);
	if (j == -1)
		printf("dump error");
	else if (j == -2)
		printf("-n error");
	else if (j == -3)
		printf("file error");
	else if (j == -4)
		printf("too much players");
	if (j != 1)
		return (1);
	inject_players(env);
	if (DISPLAY)
		init_display(env);
	process_turn(env);
	return (0);
}
