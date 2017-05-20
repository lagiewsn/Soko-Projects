#include "sokoban.h"
#include <stdio.h>
#include <gtk/gtk.h>


int main(int argc, char ** argv) {

/* Initialisation de GTK+ */
	gtk_init(&argc, &argv);

	GtkWidget * MainWindow = NULL;
	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	void gtk_widget_show(MainWindow);
	gtk_main();



	Position pos;
	Position newPos;
	int compteur = 0;
Grille initiale = {
 "########################",
 "#.........#......#.....#",
 "##......###............#",
 "###..............#.....#",
 "####.............#.....#",
 "##################.....#",
 "####.............#.....#",
 "###..oo..............###",
 "##..SOO......#########.#",
 "#......................#",
 "#......................#",
 "########################"
};
	Grille nouvelle;
	Boolean condition = false;
	Commande test;
	
	nouveauJeu(initiale, nouvelle);

	while(!condition) {

		afficheGrille(nouvelle);
		printf("> ");
		char commande[MAXCH+1];
		if(fgets(commande,MAXCH,stdin) == NULL ) {
			error(BAD_ENTRY);
		}

		test = commande[0];
		ajaxvitre;

		if(verifCommande(test)) {

			pos = getSokoban(nouvelle);
			newPos = joue(nouvelle, test, pos, initiale);
			compteur++;
		}

		condition=gagne(nouvelle, newPos, initiale, compteur);
		
	}



	return EXIT_SUCCESS;
}

