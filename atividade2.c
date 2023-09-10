#include <ncurses.h>

int main()
{
	initscr();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	float valor1, valor2, resultado;
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
	mvwprintw(win, 4, 1, "Ola, digite a distancia percorrida.");
	mvwscanw(win, 5, 1, "%f", &valor1);
	wrefresh(win);
	mvwprintw(win, 9, 1, "Agora digite o total de litros gastos:");
	mvwscanw(win, 10, 1, "%f", &valor2);
	resultado = valor1/valor2;
	wrefresh(win);
	mvwprintw(win, 14, 1, "Consumo medio: %.2f Km/l", resultado);
	wrefresh(win);
	wgetch(win);
       	endwin();
	
	return 0;
}
