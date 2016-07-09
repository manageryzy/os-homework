/*
 * process.c
 *
 *  Created on: Jul 9, 2016
 *      Author: manageryzy
 */

#include "process.h"

void print_menu(){
	int row,col;
	getmaxyx(stdscr,row,col);
	mvprintw(0,35,"process");
	mvprintw(1,4,"1-matrix");
	mvprintw(3,4,"2-add user");
	mvprintw(5,4,"3-thief");
	mvprintw(7,4,"4-phi");
	mvprintw(9,4,"7-shell");
	mvprintw(row-1,4,"q-exit");
	refresh();
}

int main(int argc, char **argv) {
	char ch;
	initscr();
	noecho();
	print_menu();
	while((ch=getchar())!='q'){
		switch(ch){
		case '1':
			endwin();
			echo();
			system("clear");
			system("../../01-matrix/Release/01-matrix");
			getch();
			noecho();
			initscr();
			print_menu();
			break;
		case '2':
			endwin();
			echo();
			system("clear");
			system("../../02-script/adduser.sh");
			getch();
			noecho();
			initscr();
			print_menu();
			break;
		case '3':
			endwin();
			echo();
			system("clear");
			system("../../03-thief/Release/03-thief");
			getch();
			noecho();
			initscr();
			print_menu();
			break;
		case '4':
			endwin();
			echo();
			system("clear");
			system("../../04-phi/Release/04-phi");
			getch();
			noecho();
			initscr();
			print_menu();
			break;
		case '7':
			endwin();
			echo();
			system("clear");
			system("../../07-shell/Release/07-shell");
			getch();
			noecho();
			initscr();
			print_menu();
			break;
		}
	}
	endwin();
	echo();
}

