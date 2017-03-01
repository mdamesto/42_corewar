/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:28 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/01 10:16:16 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_player		*file_parser(int fd)
{

	t_player *player;
	unsigned char *buf = (unsigned char *)malloc((2048 > CHAMP_MAX_SIZE) ? 2048 : CHAMP_MAX_SIZE);
	unsigned int bufint;
	int i = 0;

	player = player_init();

	read(fd, buf, 4);
	bufint = (buf[1] << 16) + (buf[2] << 8) + buf[3];
	if (bufint != COREWAR_EXEC_MAGIC)
	{
		printf("header error : %#x vs %#x\n", bufint, COREWAR_EXEC_MAGIC);
		//return (0);
	}
	read(fd, buf, 128);
	player->name = ft_strcpy(player->name, (char *)buf);
	read(fd, buf, 4); // kill decalage
	read(fd, buf, 4);
	bufint = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	if (bufint > CHAMP_MAX_SIZE)
	{
		printf("error size, too big : %d vs %d\n", bufint, CHAMP_MAX_SIZE);
		//return (0);
		player->instructions_size = bufint;

	}
	else
		player->instructions_size = bufint;
	read(fd, buf, 2048+4); // kill comments & decalage
	while (read(fd, buf, 1))
	{
		player->instructions[i] = *buf;
		i++;
		if ((unsigned int)i > bufint)
		{
			printf("\nerror instructions count : %d vs %d\n", i, bufint);
			return (NULL);
		}
	}
	if ((unsigned int)i != bufint)
	{
		printf("\nerror instructions count : %d vs %d\n", i, bufint);
		return (NULL);
	}
	free(buf);
	return (player);
}

static int		get_dump(int ac, char **av)
{
	int dump_value;

	if (ac < 3)
		return (-1);
	if (!ft_isint(av[2]))
		return (-1);
	dump_value = ft_atoi(av[2]);
	if (dump_value < 0)
		return (-1);
	ft_printf("DUMP OK\n");
	return (dump_value);
}

int		arg_parser(int ac, char **av, t_env *env)
{
	int i = 1;
	int fd;
	int j = 0;
	int k = 0;
	int l = 1;

	if (ac >= 3 && !ft_strcmp("-dump", av[1]))
	{
		if (get_dump(ac, av) == -1)
			return (-1);
		i += 2;
	}
	while (i != ac)
	{
		if (!ft_strcmp("-n", av[i]))
		{
			if (i+2 < ac && ft_isint(av[i+1]) && ft_atoi(av[i+1]) > 0)
				k = ft_atoi(av[i+1]);
			else
				return (-2);
			i += 2;
		}
		if ((fd = open(av[i], O_RDONLY)) != -1)
		{
			env->arena->player_amount++;
			if (env->arena->player_amount > MAX_PLAYERS)
				return (-4);
			env->player_list[j] = file_parser(fd);
			if (k)
			{
				env->player_list[j]->number = k;
				k = 0;
			}
			else
			{
				env->player_list[j]->number = l;
				l++;
			}
			env->player_list[j+1] = NULL;
			j++;
		}
		else
			return (-3);
		i++;
	}
	return (1);
}
