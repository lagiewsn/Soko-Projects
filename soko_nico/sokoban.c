#include "sokoban.h"
#include <stdio.h>
#include <stdlib.h>

void afficheGrille(Grille grille)
{
	int j;
	int i;
	printf("\n");

	for(i=0; i != HAUTEUR; i++) {
		for(j = 0; j != LARGEUR + 1; j++) {
			printf("%c", grille[i][j]);
		}
		printf("\n");
	}
} 

Position getSokoban(Grille grille)
{
	int j;
	int i;
	Boolean test = false;
	Position position;

	for(i=0; i != HAUTEUR; i++) {
		for(j = 0; j != LARGEUR + 1; j++) {
			if(grille[i][j] == SOKOBAN) {
				position.ligne = j;
				position.colonne = i;
				test = true;
			}
		}
	}
	if(test == false) 
	{
			position.ligne = 0;
			position.colonne = 0;
	}
	
	return position;

} 

 void error(CodeError code)
  {
    switch (code) {
     case NO_SOKOBAN : fprintf(stderr,"pas de Sokoban!\n"); break;
     default: fprintf(stderr,"code erreur inconnu!\n");
    }
    exit(code);
  }/*error*/

void nouveauJeu(Grille init, Grille g) {
	
	int j;
	int i;

	for(i=0; i != HAUTEUR; i++) {
		for(j = 0; j != LARGEUR + 1; j++) {
			g[i][j] = init[i][j];
		}
	}
	
	for(i=0; i != HAUTEUR; i++) {
		for(j = 0; j != LARGEUR + 1; j++) {
			if(init[i][j] == CAISSE || init[i][j] == SOKOBAN) {
				init[i][j] = VIDE;
			}
		}
	}


}