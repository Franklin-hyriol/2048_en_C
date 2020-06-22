#include "headers/menu.h"

void menu(){

	show_cursor(false); //ne pas voire le curseur
	char choix_menu = 0;

	system("cls"); // effacer l'ecran
    set_color(15); //couleur blanc
	printf("\n\n\t   __________________________________\n");
	printf("\t / \\                                 \\.\n");
	printf("\t|   |                                |.\n");
	printf("\t \\_ |                                |.\n");
	printf("\t    |                                |.\n");
    printf("\t    |                                |.\n");
    printf("\t    |                                |.\n");
    printf("\t    |                                |.\n");
    printf("\t    |                                |.\n");    
	printf("\t    |                                |.\n");
	printf("\t    |                                |.\n");
	printf("\t    |                                |.\n");	
	printf("\t    |                                |.\n");
	printf("\t    |                                |.\n");
	printf("\t    |   _____________________________|___\n");
	printf("\t    |  /                                /.\n");
	printf("\t    \\_/________________________________/.\n");
	printf("\t                                  by FH   \n");

	set_color(1); //couleur blue claire
	gotoxy(15, 4);
	printf("#####  #####     ##   #####");
	gotoxy(15, 5);
	printf("   #   #   #    # #   #   #");
	gotoxy(15, 6);
	printf("  #    #   #   #  #   #####");
	gotoxy(15, 7);
	printf(" #     #   #  ######  #   #");
	gotoxy(15, 8);
	printf("#####  #####      #   #####");

	set_color(6); // jaune
	gotoxy(20, 11);
	printf("1>Nouvelle partie");
	gotoxy(23, 12);
	set_color(4); // rouge
	printf("2>Quitter");
	gotoxy(19, 15);
	set_color(10); //vert claire
	printf("(?)appuie sur 1 ou 2");
	do{
		while(kbhit()){
			choix_menu = getch();
			switch(choix_menu){
				case '1':
					initialisation(); //lancement du jeux 
				   break;
				case '2':
					quitter();
					return EXIT_SUCCESS;
				default:
					continue;
			}

		}
	}while(true);
}
