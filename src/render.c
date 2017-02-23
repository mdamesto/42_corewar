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

static void	handle_att(t_env *env, t_display *display, int use)
{
	int (*fct_1)(WINDOW *, int);
	int (*fct_2)(WINDOW *, int);

	fct_1 = use ? wattron : wattroff;
	fct_2 = use ? wattroff : wattron; 

	if (display->ispc)
	{
		if (display->value > 0 && display->value < 17)
			fct_1(env->w_main, COLOR_PAIR(display->champion + 4));
		else
			fct_1(env->w_main, COLOR_PAIR(display->champion + 8));
	}
	else if (display->champion)
		fct_1(env->w_main, COLOR_PAIR(display->champion));
	if (display->recent_display)
	{
		fct_2(env->w_main, A_BOLD);
		if (!use)
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
    wbkgd(main, COLOR_PAIR(13));
    wbkgd(menu, COLOR_PAIR(13));
    env->w_main = main;
    env->w_menu = menu;
	wattron(env->w_main, A_BOLD);
}

void 	display(t_display **display, t_env *env)
{

	const char hex[] = "0123456789abcdef";
	char str[3];
	int i;
	char ch;

	str[2] = '\0';
	i = -1;
	while(++i < 4096)
	{
		handle_att(env, display[i], 1);
		str[0] = hex[display[i]->value / 16];
		str[1] = hex[display[i]->value % 16];
		mvwprintw(env->w_main, LINE(i), COL(i), str);
		handle_att(env, display[i], 0);
		mvwprintw(env->w_main, LINE(i), COL(i) + 2, " ");
	}
	wrefresh(env->w_main);

	/*if ((ch = getch()) == ' ')
	{
		ft_putstr_fd("PAUSED\n", debugfd);
		ungetch(ch);
		while ((ch = getch()) != ' ')
		{
			if (ch == 67)
				ft_putstr_fd("STEP BY STEP\n", debugfd);
		}
	}*/

	/*ft_putstr_fd("KEYBOARD NOT HITTED\n", debugfd);
	ch = getch();
	if (ch == ERR)
		ft_putstr_fd("CH = ERR\n", debugfd);
	*/

	if ((ch = getch()) != ERR)
	{
		/*ft_putstr_fd("KEYBOARD HITTED\n", debugfd);
		ft_putstr_fd("CH = \'", debugfd);
		write(debugfd, &ch, 1);
		ft_putstr_fd("\'.\n", debugfd);*/

		if (ch == 65)
			ft_putstr_fd("UP SPEED\n", debugfd);
		else if (ch == 66)
			ft_putstr_fd("DOWN SPEED\n", debugfd);
		else if (ch == ' ' || ch == 67)
		{
			if (ch == ' ')
				ft_putstr_fd("PAUSED....\n", debugfd);
			if (ch == 67)
				ft_putstr_fd("STEP BY STEP\n", debugfd);
			while ((ch = getch()) != ' ')
			{
				if (ch == 65)
					ft_putstr_fd("UP SPEED\n", debugfd);
				else if (ch == 66)
					ft_putstr_fd("DOWN SPEED\n", debugfd);
				else if (ch == 67)
					ft_putstr_fd("STEP BY STEP\n", debugfd);
			}
			ft_putstr_fd("UNPAUSED!\n", debugfd);
		}
	}
}

void	end_display(t_env * env)
{
	free(env->w_main);
	free(env->w_menu);
	endwin();
}
