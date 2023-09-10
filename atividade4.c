#include <ncurses.h>

int main()
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);

	float valor1, resultado;
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
	mvwprintw(win, 4, 1, "Ola, digite o valor em graus Fahrenheit:");
	mvwscanw(win, 5, 1, "%f", &valor1);
	wrefresh(win);
	resultado = (valor1 - 32)/1.8;
	wrefresh(win);
	mvwprintw(win, 14, 1, "Tempera em Celsius: %.2f", resultado);
	wrefresh(win);
	wgetch(win);
       	endwin();
	
	return 0;
}
