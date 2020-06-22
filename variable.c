#include "headers/variable.h"
	//initiation de tout les cases du jeux à 0
void init_tab(){
	int i,j;
	for(i=0; i<taille; i++){
		game_tab[i] = (int *)malloc(taille * sizeof(int)); //alocation dynamitque tableau 2D
		for(j=0; j<taille; j++){
			game_tab[i][j] = 0;
		}
	}
}

