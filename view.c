#include "headers/view.h"

int affiche(int score){
	system("cls");
	int i,j;
    static int score_actuelle = 0;

    if(score == -1){
        score_actuelle = 0;
    }else if(score == -2){
        system("cls");
        set_color(4); //couleur rouge
        gotoxy(12, 7);
        printf("GAME OVER\n");
        gotoxy(12, 8);
        set_color(6); //joune
        printf("Score: %d\n", score_actuelle);
        gotoxy(12, 10);
        set_color(2); //vert
        printf("appuier sur entrer pour quitter\n");
        getchar();
        quitter();
    }else{
        score_actuelle += score;
    }

/////case
	set_color(4);
	printf("\n\n\t\t2048\n");
	set_color(15);
	printf("\t_____________________\n");
	printf("\t|    |    |    |    |\n");
	printf("\t|____|____|____|____|\n");
	printf("\t|    |    |    |    |\n");
	printf("\t|____|____|____|____|\n");
	printf("\t|    |    |    |    |\n");
	printf("\t|____|____|____|____|\n");
	printf("\t|    |    |    |    |\n");
	printf("\t|____|____|____|____|\n");
///////fin case

//////bombe rouge
    set_color(4);
    gotoxy(32, 7);
    printf("______________________");
    gotoxy(31, 8);
    printf("/                    / \\");
    gotoxy(30, 9);
    printf("|      SCORE:        |");
    gotoxy(31, 10);
    printf("\\____________________\\_/");
    set_color(15);
    gotoxy(54,9);
    printf("========");
    set_color(6);
    gotoxy(60, 7);
    printf("\\  | / ");
    gotoxy(60, 8);
    printf("\\ \\*/ /");
    gotoxy(60, 9);
    printf("** -*-");
    gotoxy(60, 10);
    printf("/ /*\\ \\");
    gotoxy(60, 11);
    printf("/ |  \\");

    //////###afficher le score sur l'ecran
    gotoxy(44, 9);
    set_color(6);
    if(score_actuelle<10)
        printf("000%d", score_actuelle);
    else if(score_actuelle<100)
        printf("00%d", score_actuelle);
    else if(score_actuelle<1000)
        printf("0%d", score_actuelle);
    else
        printf("%d", score_actuelle);

/////////fin bombe rouge

///////////help

    set_color(2);
    gotoxy(30, 4);
    printf("R:Nouvelle partie");
    gotoxy(30, 5);
    printf("Q:Quiter");
    gotoxy(30, 6);
    printf("->Utiliser les fleches de direction pour jouer");

////////////////////////////

////mise en place des nombre dans la case
    for(i=0; i<taille; i++){
    	for(j=0; j<taille; j++){
    		if(game_tab[i][j] == 0){ // si le tableau est vide
    			if(i == 0){/////1 ere ligne
    				if(j==0){//1 colone
    					gotoxy(10, 4);
						printf("   ");
    				}else if(j==1){//2
    					gotoxy(15, 4);
						printf("   ");
    				}else if(j==2){//3
    					gotoxy(20, 4);
						printf("   ");
    				}else{//4
    					gotoxy(25, 4);
						printf("   ");
    				}
    			}else if(i == 1){/////2 eme ligne
    				if(j==0){//1 colone
    					gotoxy(10, 6);
						printf("   ");
    				}else if(j==1){//2
    					gotoxy(15, 6);
						printf("   ");
    				}else if(j==2){//3
    					gotoxy(20, 6);
						printf("   ");
    				}else{//4
    					gotoxy(25, 6);
						printf("   ");
    				}
    			}else if(i == 2){////3 eme ligne
    				if(j==0){//1 colone
    					gotoxy(10, 8);
						printf("   ");
    				}else if(j==1){//2
    					gotoxy(15, 8);
						printf("   ");
    				}else if(j==2){//3
    					gotoxy(20, 8);
						printf("   ");
    				}else{//4
    					gotoxy(25, 8);
						printf("   ");
    				}
    			}else{//////4 eme ligne
    				if(j==0){//1 colone
    					gotoxy(10, 10);
						printf("   ");
    				}else if(j==1){//2
    					gotoxy(15, 10);
						printf("   ");
    				}else if(j==2){//3
    					gotoxy(20, 10);
						printf("   ");
    				}else{//4
    					gotoxy(25, 10);
						printf("   ");
    				}
    			}
    		}else{ //si le tableau n'est pas vide
    			int a,b,c,d;
    			if(game_tab[i][j] < 1024){ //pour que les nombre 4 chiffres ne depace pas la case
    				a = 10;
    				b = 15;
    				c = 20;
    				d = 25;
    			}else{
    				a = 9;
    				b = 14;
    				c = 19;
    				d = 24;
    			}

    			if(i == 0){/////1 ere ligne
    				if(j==0){//1 colone
    					gotoxy(a, 4);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==1){//2
    					gotoxy(b, 4);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==2){//3
    					gotoxy(c, 4);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else{//4
    					gotoxy(d, 4);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}
    			}else if(i == 1){/////2 eme ligne
    				if(j==0){//1 colone
    					gotoxy(a, 6);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==1){//2
    					gotoxy(b, 6);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==2){//3
    					gotoxy(c, 6);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else{//4
    					gotoxy(d, 6);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}
    			}else if(i == 2){////3 eme ligne
    				if(j==0){//1 colone
    					gotoxy(a, 8);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==1){//2
    					gotoxy(b, 8);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==2){//3
    					gotoxy(c, 8);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else{//4
    					gotoxy(d, 8);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}
    			}else{//////4 eme ligne
    				if(j==0){//1 colone
    					gotoxy(a, 10);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==1){//2
    					gotoxy(b, 10);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else if(j==2){//3
    					gotoxy(c, 10);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}else{//4
    					gotoxy(d, 10);
    					set_color(color(game_tab[i][j]));
						printf("%d", game_tab[i][j]);
    				}
    			}
    			
    		}
    	}
    }
}


////////////////////////////////////// 


int color(int game_tab_nombre){ //couleur des nombres
	int color;
	switch(game_tab_nombre){
		case 2:
			color = 1;
			break;
		case 4:
			color = 2;
			break;
		case 8:
			color = 3;
			break;
		case 16:
			color = 4;
			break;
		case 32:
			color = 5;
			break;
		case 64:
			color = 6;
			break;
		case 128:
			color = 9;
			break;
		case 256:
			color = 10;
			break;
		case 512:
			color = 11;
			break;
		case 1024:
			color = 12;
			break;
		case 2048:
			color = 13;
			break;		
		default:
			color = 15;
			break;
	}
	
return color;
}