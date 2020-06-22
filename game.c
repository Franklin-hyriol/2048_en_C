#include "headers/game.h"

void chargement(char *string){
	system("cls"); //effacer l'ecran
	gotoxy(15, 10); //deplacer le curseur
	set_color(10); //vert claire
	printf("%s\n", string);
	Sleep(500); //attendre 1 seconde
}

////////////////////////////////////////////////////

void initialisation(){

	int score = -1;

	srand(time(NULL));
	int coord1 = rand()%4; //coordonnee x du premiere nombre aleatoire

	chargement("Chargement.20%");	

	srand(time(NULL));
	int coord2 = rand()%4; //coordonnee y du premiere nombre aleatoire

	chargement("Chargement..40%");

	srand(time(NULL));
	int coord11 = rand()%4; //coordonnee x du deuxieme nombre aleatoire

	chargement("Chargement...60%");	

	srand(time(NULL));
	int coord22 = rand()%4; //coordonnee y du deuxieme nombre aleatoire

	chargement("Chargement....80%");

	if(coord1 == coord11 && coord2 == coord22){ //eviter d'avoir le meme coordonnee pour les deux nombre
		if(coord2 > 4){
			coord2--;
		}else{
			coord2++;
		}
	}

	init_tab(); //initiation de tout les cases du jeux à 0

	game_tab[coord1][coord2] = nombre_aleatoire();

	chargement("Chargement.....100%");

	game_tab[coord11][coord22] = nombre_aleatoire();

	affiche(score); //affiche le jeux sur l'ecran
	boucle_game();

}


///////////////////////////////////////////////////////////


int nombre_aleatoire(){
	srand(time(NULL));
	int nombre = rand()%5; //nombre aleatoire < 5

	if(nombre == 0 || nombre == 1 || nombre == 2){
		nombre = 2;
	}else{
		nombre = 4;
	}

return nombre;
}


/////////////////////////////////
void nouveau_nombre(int score){
	int nombre = nombre_aleatoire(), i,j;

	srand(time(NULL));
	do{
		i = rand()%4;
		j = rand()%4;
	}while(game_tab[i][j] != 0);
	game_tab[i][j] = nombre;

	affiche(score);
}


////////////////////////////////boucle du jeux


void boucle_game(){
	bool game_over = false;
	int touche,i,j,k1,k2,k3; 
	while(!game_over){
		while(kbhit()){
			touche = getch();
			switch(touche){
				case 75: // direction <-
					k1 = RetasseGauche();
					k2 = AdditionneGauche();
					k3 = RetasseGauche();
					nouveau_nombre(k2);
					break;
				case 72: //direction ^
					k1 = RetasseHaut();
					k2 = AdditionneHaut();
					k3 = RetasseHaut();
					nouveau_nombre(k2);
					break;
				case 77: //direction ->
					k1 = RetasseDroite();
					k2 = AdditionneDroite();
					k3 = RetasseDroite();
					nouveau_nombre(k2);
					break;
				case 80: //direction v
					k1 = RetasseBas();
					k2 = AdditionneBas();
					k3 = RetasseBas();
					nouveau_nombre(k2);
					break;
				case 113:
					quitter();
					break;
				case 114:
					nouvelle_partie();
					break;
				default:
					break;
			}
			test_game_over();
		}
	}
}


//////////////////////////////


int RetasseGauche(){
	int i,j,k,l=0;
	for (i=0;i<taille;i++)
	{
		k=0;
		for(j=0;j<taille;j++)
			if (game_tab[i][j]!=0)
			{
				game_tab[i][k]=game_tab[i][j];
				if(k<j)
					{game_tab[i][j]=0;l=1;}
				k++;
			}
		}
	return l;
}

int RetasseHaut(){
	int i,j,k,l=0;
	for (j=0;j<taille;j++)
	{
		k=0;
		for(i=0;i<taille;i++)
			if (game_tab[i][j]!=0)	
			{
				game_tab[k][j]=game_tab[i][j];
				if(k<i)
					{game_tab[i][j]=0;l=1;}
				k++;
			}
	}
	return l;
}

int RetasseDroite(){
	int i,j,k,l=0;
	for (i=0;i<taille;i++)
	{	
		k=taille-1;
		for(j=taille-1;j>=0;j--)
			if (game_tab[i][j]!=0)
			{
				game_tab[i][k]=game_tab[i][j];
				if(k>j)
					{game_tab[i][j]=0;l=1;}		
				k--;
			}
	}			
	return l;
}

int RetasseBas(){
	int i,j,k,l=0;
	for(j=0;j<taille;j++)
	{
		k=taille-1;
		for (i=taille-1;i>=0;i--)
			if (game_tab[i][j]!=0)	
			{
				game_tab[k][j]=game_tab[i][j];
				if(k>i){
					game_tab[i][j]=0;
					l=1;
				}
				k--;
			}
	}
	return l;
}

//////////////////////////////////

int AdditionneGauche()
{
	int i,j,score=0;
	for(i=0;i<taille;i++)
		for(j=0;j<taille-1;j++)
			if(game_tab[i][j]==game_tab[i][j+1])
			{	
				game_tab[i][j]=game_tab[i][j]+game_tab[i][j+1];
				score+=game_tab[i][j];
				game_tab[i][j+1]=0;
			}
	return score;
}

int AdditionneHaut()
{
	int i,j,score=0;
	for(i=0;i<taille-1;i++)
		for(j=0;j<taille;j++)
			if(game_tab[i][j]==game_tab[i+1][j])
			{	
				game_tab[i][j]=game_tab[i][j]+game_tab[i+1][j];
				score+=game_tab[i][j];
				game_tab[i+1][j]=0;
			}
	return score;
}

int AdditionneDroite(){
	int i,j,score=0;
	for(i=0;i<taille;i++)
		for(j=taille-1;j>0;j--)
			if(game_tab[i][j]==game_tab[i][j-1])
			{	
				game_tab[i][j]=game_tab[i][j]+game_tab[i][j-1];
				score+=game_tab[i][j];
				game_tab[i][j-1]=0;
			}
	return score;
}

int AdditionneBas(){
	int i,j,score=0;
	for(i=taille-1;i>0;i--)
		for(j=0;j<taille;j++)
			if(game_tab[i][j]==game_tab[i-1][j])
			{	
				game_tab[i][j]=game_tab[i][j]+game_tab[i-1][j];
				score+=game_tab[i][j];
				game_tab[i-1][j]=0;
			}
	return score;
}


/////////////////////////////////

void nouvelle_partie(){
	int i,j;
	for(i=0; i<taille; i++){
		for(j=0; j<taille; j++){
			game_tab[i][j] = 0;
		}
	}
	initialisation();
}

////////////////////////////////////

void test_game_over(){
	int i,j,k;
	int game_tab_copy[taille][taille];

	for(i=0; i<taille; i++){
		for(j=0; j<taille; j++){
			game_tab_copy[i][j] = game_tab[i][j];
		}
	}

	k = RetasseGauche();
	k += RetasseHaut();
	k += RetasseBas();
	k += RetasseDroite();


	if(k == 0){
		affiche(-2);
	}

	for(i=0; i<taille; i++){
		for(j=0; j<taille; j++){
			game_tab[i][j] = game_tab_copy[i][j];
		}
	}
}