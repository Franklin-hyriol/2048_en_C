#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "creaco.h"
#include "view.h"
#include "OnExit.h"
#include "variable.h"

	void initialisation();
	void chargement(char *string);
	int nombre_aleatoire();
	void nouveau_nombre(int score);
	void boucle_game();
	void nouvelle_partie();
	void test_game_over();

	int RetasseGauche();
	int RetasseHaut();
	int RetasseDroite();
	int RetasseBas();

	int AdditionneGauche();
	int AdditionneHaut();
	int AdditionneDroite();
	int AdditionneBas();
#endif