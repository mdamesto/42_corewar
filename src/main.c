/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:54:36 by jde-maga          #+#    #+#             */
/*   Updated: 2017/02/23 19:14:37 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int debugfd = -1;

void hexa_dump(unsigned char *memory, int size)
{
	int i = 1;
	while (i-1 != size)
	{
		if (memory[i-1] <= 15)
			ft_printf("0");
		ft_printf("%x ", memory[i-1]);
		if (i % 32 == 0)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void inject_players(t_env *env)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (env->player_list[i])
	{
		env->process_list[i] = process_init(env->player_list[i]->number, i + 1);
		env->process_list[i]->reg[0] = swap_bytes(env->player_list[i]->number);
		env->arena->process_amount++;
		i++;
	}
	i = 0;
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
		pc = (pc + 1) % MEM_SIZE;
	return (pc);
}

void	process_turn(t_env *env)
{
	int opcode = 0;
	int	param = 0;
	int pc;

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
				if (!(opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15))
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
		display(env->display, env);
	}
}

int main(int argc, char **argv)
{
	t_env *env;

	env = env_init();

	debugfd = open("/dev/ttys002", O_WRONLY);

	if (argc == 1)
	{
		ft_printf("no commmands\n");
		return (0);
	}
	int j = arg_parser(argc, argv, env);
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
