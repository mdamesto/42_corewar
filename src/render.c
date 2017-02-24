#include <corewar.h>
#include <ncurses.h>

# define LINE(i) (i) / 64
# define COL(i) ((i) % 64) * 3

static void   my_init_color()
{
    start_color();

    //CHMP_COLOR
    init_pair(1, COLOR_BLUE, COLOR_WHITE);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_YELLOW, COLOR_WHITE);
    init_pair(4, COLOR_MAGENTA, COLOR_WHITE);

    //PC on INVALID OP_CODE
    init_pair(5, COLOR_WHITE, COLOR_BLUE);
    init_pair(6, COLOR_WHITE, COLOR_GREEN);
    init_pair(7, COLOR_WHITE, COLOR_YELLOW);
    init_pair(8, COLOR_WHITE, COLOR_MAGENTA);

    //PC on INVALID OP_CODE
    init_pair(9, COLOR_RED, COLOR_BLUE);
    init_pair(10, COLOR_RED, COLOR_GREEN);
    init_pair(11, COLOR_RED, COLOR_YELLOW);
    init_pair(12, COLOR_RED, COLOR_MAGENTA);

    //COLOR OF UNUSED MEM
    init_pair(13, COLOR_BLACK, COLOR_WHITE);
}

// ATT_ON AND ATT_OFF CAN BE ONE FCT (USING *FCT)  ----------------- TODO
static void	att_on(t_env *env, t_display *display)
{
	if (display->ispc)
	{
		if (display->value > 0 && display->value < 17)
			wattron(env->w_main, COLOR_PAIR(display->champion + 4));
		else
			wattron(env->w_main, COLOR_PAIR(display->champion + 8));
	}
	else if (display->champion)
		wattron(env->w_main, COLOR_PAIR(display->champion));
	if (display->recent_display)
		wattroff(env->w_main, A_BOLD);
}

static void	att_off(t_env *env, t_display *display)
{
	if (display->ispc)
	{
		if (display->value > 0 && display->value < 17)
			wattroff(env->w_main, COLOR_PAIR(display->champion + 4));
		else
			wattroff(env->w_main, COLOR_PAIR(display->champion + 8));
	}
	else if (display->champion)
		wattroff(env->w_main, COLOR_PAIR(display->champion));
	if (display->recent_display)
	{
		wattron(env->w_main, A_BOLD);
		display->recent_display--;
	}
}

void init_display(t_env *env)
{
    WINDOW *main;
    WINDOW *menu;

    initscr();

    //NCURSES OPTION/CONFIG
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);

    //INIT COLOR AND SUBWINDOWS and STORE IN ENV
    my_init_color();
    main = subwin(stdscr, 64, 193, 1, 1);
    menu = subwin(stdscr, 64, 40, 1, 196);
    wbkgd(main, COLOR_PAIR(13));
    wbkgd(menu, COLOR_PAIR(13));
    env->w_main = main;
    env->w_menu = menu;
	wattron(env->w_main, A_BOLD);


	ft_putstr_fd("succesinit\n", debugfd);
}

void 	display(t_display **display, t_env *env)
{
	ft_putstr_fd("in display iter\n", debugfd);
	const char hex[] = "0123456789abcdef";
	char str[3];
	int i;

	str[2] = '\0';
	i = -1;
	while(++i < 4096)
	{
		att_on(env, display[i]);
		str[0] = hex[display[i]->value / 16];
		str[1] = hex[display[i]->value % 16];
		mvwprintw(env->w_main, LINE(i), COL(i), str);
		att_off(env, display[i]);
		mvwprintw(env->w_main, LINE(i), COL(i) + 2, " ");
	}
	wrefresh(env->w_main);
}

void	end_display(t_env * env)
{
	free(env->w_main);
	free(env->w_menu);
	endwin();
}
