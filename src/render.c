/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:02:22 by jde-maga          #+#    #+#             */
/*   Updated: 2017/03/09 16:36:34 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <ncurses.h>

#define LINE(i) (i) / 64
#define COL(i) ((i) % 64) * 3

static void	update_champion_live(t_env *env)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (env->player_list[i])
	{
		if (env->player_list[i]->isalive == 1)
			mvwprintw(env->w_menu, 14 + j, 16, "YES     ");
		else if (env->player_list[i]->isalive == 0)
			mvwprintw(env->w_menu, 14 + j, 16, "NO      ");
		else if (env->player_list[i]->isalive == -1)
			mvwprintw(env->w_menu, 14 + j, 16, "K.I.A   ");
		i++;
		j += 3;
	}
}

void		set_attributes(WINDOW *w_main, t_display *display)
{
	if (!display->champion)
		wattron(w_main, COLOR_PAIR(255));
	if (display->forked)
		wattron(w_main, COLOR_PAIR(display->champion * 10 + 3));
	else if (display->ispc && (display->value < 1 || display->value > 16))
		wattron(w_main, COLOR_PAIR(display->champion * 10 + 2));
	else if (display->ispc)
		wattron(w_main, COLOR_PAIR(display->champion * 10 + 1));
	else
		wattron(w_main, COLOR_PAIR(display->champion * 10));
	if (display->recent_display)
		wattron(w_main, A_BOLD);
	else
		wattroff(w_main, A_BOLD);
}

void		display(t_env *env)
{
	const char	hex[] = "0123456789abcdef";
	int			i;
	char		str[3];

	str[2] = '\0';
	i = -1;
	while (++i != 4096)
	{
		str[0] = hex[env->display[i]->value / 16];
		str[1] = hex[env->display[i]->value % 16];
		set_attributes(env->w_main, env->display[i]);
		mvwprintw(env->w_main, LINE(i), COL(i), "%s", str);
		if (env->display[i]->recent_display)
			env->display[i]->recent_display--;
		if (env->display[i]->forked)
			env->display[i]->forked--;
	}
	mvwprintw(env->w_menu, 1, 27, "%d", env->arena->current_cycle);
	mvwprintw(env->w_menu, 3, 27, "%d\t",
			env->arena->cycle_to_die - env->arena->live_cycle - 1);
	mvwprintw(env->w_menu, 5, 27, "%d\t", env->arena->cycle_to_die);
	mvwprintw(env->w_menu, 8, 27, "%d", env->arena->process_amount);
	update_champion_live(env);
	wrefresh(env->w_menu);
	wrefresh(env->w_main);
}
