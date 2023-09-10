#include<stdio.h>
#include<math.h>
#include<ncurses.h>

int main()
{
	initscr();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);

	float valor1, valor2, quadrado_hip, resultado;
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
	mvwprintw(win, 4, 1, "Ola, digite o valor do cateto 1.");
	mvwscanw(win, 5, 1, "%f", &valor1);
	wrefresh(win);
	mvwprintw(win, 9, 1, "Agora digite o valor do cateto 2:");
	mvwscanw(win, 10, 1, "%f", &valor2);
	quadrado_hip = (valor1 * valor1) + (valor2 * valor2);
	resultado = sqrt(quadrado_hip);
	wrefresh(win);
	mvwprintw(win, 14, 1, "hipotenusa: %.2f", resultado);
	wrefresh(win);
	wgetch(win);
       	endwin();
	
	return 0;
}
