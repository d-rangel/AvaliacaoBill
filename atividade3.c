#include <ncurses.h>

int main()
{
	initscr();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);

	char caracter;
	int alt, larg, start_x, start_y;
	alt = 20;
	larg = 40;
	start_x = (COLS - larg)/2;
	start_y = (LINES - alt)/2;				
    
    	WINDOW * win = newwin(alt, larg, start_y, start_x);
	wattron(win, COLOR_PAIR(1));
    	refresh();
	box(win, 0, 0);
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwprintw(win, 5, 1, "Ola, digite um caracter.");
	mvwscanw(win, 6, 1, "%c", &caracter);
	wrefresh(win);
	mvwprintw(win, 10, 1, "O caracter escolhido foi: %c", caracter);
	mvwprintw(win, 11, 1, "Seu codigo ASCII em decimal: %d", caracter);
	mvwprintw(win, 12, 1, "Seu codigo ASCII em hexadecimal: %x", caracter);
	wrefresh(win);
	wgetch(win);
       	endwin();
	return 0;
}
