#include "corewar.h"

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
static void	att_on(t_display *display)
{
	if (display->ispc)
	{
		if (display->value > 0 && display->value < 17)
			wattron(env->w_main, COLOR_PAIR(display->champ_nb + 4));
		else
			wattron(env->w_main, COLOR_PAIR(display->champ_nb + 8));
	}
	else if (display->champ_nb)
		wattron(env->w_main, COLOR_PAIR(display->champ_nb));
	if (display->recent_display)
		wattron(env->w_main, A_BOLD);
}

static void	att_off(t_display *display)
{
	if (display->ispc)
	{
		if (display->value > 0 && display->value < 17)
			wattroff(env->w_main, COLOR_PAIR(display->champ_nb + 4));
		else
			wattroff(env->w_main, COLOR_PAIR(display->champ_nb + 8));
	}
	else if (display->champ_nb)
		wattroff(env->w_main, COLOR_PAIR(display->champ_nb));
	if (display->recent_display)
	{
		wattroff(env->w_main, A_BOLD);
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
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    
    //INIT COLOR AND SUBWINDOWS and STORE IN ENV
    my_init_color();
    main = subwin(stdscr, 64, 193, 1, 1);
    menu = subwin(stdscr, 64, 40, 1, 196);
    wbkgd(main, COLOR_PAIR(9));
    wbkgd(menu, COLOR_PAIR(9));
    env->w_main = main;
    env->w_menu = menu;
}

void 	display(t_display **display, t_env *env)
{
	const char hex[] = "0123456789abcdef";
	char str[4];
	int i;

	str[2] = ' ';
	str[3] = '\0';
	i = -1;
	while(++i < 4096)
	{
		att_on(display[i]);
		str[0] = hex[value / 16];
		str[1] = hex[value % 16];
		mwwprintw(env->w_main, LINE(i), COL(i), str);
		att_off(display[i]);
	}
}

void	end_display(t_env * env)
{
	free(env->w_main);
	free(env->w_menu);
	endwin();
}