/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:28 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/09 17:53:06 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	get_instructions(t_player *player, int fd, unsigned int bufint)
{
	unsigned char	*buf;
	unsigned int	i;

	i = 0;
	buf = (unsigned char *)malloc(sizeof(unsigned char));
	while (read(fd, buf, 1))
	{
		player->instructions[i] = *buf;
		i++;
		if (i > bufint)
		{
			ft_printf("\nerror instructions count : %d vs %d\n", i, bufint);
			return (0);
		}
	}
	if (i != bufint)
	{
		ft_printf("\nerror instructions count : %d vs %d\n", i, bufint);
		return (0);
	}
	free(buf);
	return (1);
}

static int	get_bufint(t_player *player, unsigned int *bufint, int fd)
{
	unsigned char *buf;

	buf = (unsigned char *)malloc(sizeof(unsigned char) * 4);
	read(fd, buf, 4);
	*bufint = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	if (*bufint > CHAMP_MAX_SIZE)
	{
		ft_printf("error size, too big : %d vs %d\n", *bufint, CHAMP_MAX_SIZE);
		return (0);
		player->instructions_size = *bufint;
	}
	else
		player->instructions_size = *bufint;
	free(buf);
	return (1);
}

static int	check_header(int fd)
{
	unsigned char	*buf;
	unsigned int	bufint;

	buf = (unsigned char *)malloc(sizeof(unsigned char) * 4);
	read(fd, buf, 4);
	bufint = (buf[1] << 16) + (buf[2] << 8) + buf[3];
	if (bufint != COREWAR_EXEC_MAGIC)
	{
		ft_printf("header error : %#x vs %#x\n", bufint, COREWAR_EXEC_MAGIC);
		return (0);
	}
	free(buf);
	return (1);
}

t_player	*file_parser(int fd)
{
	t_player		*player;
	unsigned char	*buf;
	unsigned int	bufint;
	int				i;

	player = player_init();
	buf = (unsigned char *)malloc((2048 > CHAMP_MAX_SIZE) ?
								2048 + 4 : CHAMP_MAX_SIZE + 4);
	i = 0;
	if (!check_header(fd))
		return (NULL);
	read(fd, buf, 128);
	player->name = ft_strcpy(player->name, (char *)buf);
	read(fd, buf, 4);
	if (!get_bufint(player, &bufint, fd))
		return (NULL);
	read(fd, buf, 2048 + 4);
	if (!get_instructions(player, fd, bufint))
		return (NULL);
	free(buf);
	return (player);
}
