#include "headers/OnExit.h"

void quitter(){
	system("cls");
	set_color(15); //revenir au couleur blanc
	show_cursor(true); //reafficher le curseur
	exit(EXIT_SUCCESS);
}