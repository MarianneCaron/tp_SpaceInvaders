
#include "Coord.h"
#include "ExtraTerrestre.h"
#include "Laser.h"
#include "Martien.h"
#include "Vaisseau.h"
#include "Saisie.h"
#include "Affichage.h"
#include "Timer.h"
#include "MartienExtension.h"
#include "MartienNord.h"
#include "MartienSud.h"
#include "LaserMartien.h"
#include "Joueur.h"
#include "Jeu.h"

#include <conio.h>
#include <time.h>	// pour time(int)
#include <stdlib.h>	// pour srand(int) et rand()
#include <iostream>
using namespace std;


int main()
{

	// Assignation d'un srand pour les valeurs aléatoires
	srand((unsigned int)time(NULL));

	// Détermination des dimensions de la fenêtre de la console
	Affichage::init();

	// Affichage du menu et capture du niveau
	int niveau = Affichage::menu();

	// Variable pour rejouer
	bool rejouer = true;
	// *************************************************Le jeu**************************************** //
	do {
		
		// Affichage du cadre de jeu
		Affichage::dessinerCadre();

		// Partir la boucle du Jeu
		Jeu leJeu(niveau);
		leJeu.boucleJeu();

		// Après le jeu, gérer l'option de rejouer
		rejouer = Affichage::affichageFinPartie((ExtraTerrestre::getNombreExtraTerrestre() == 0), niveau);
		ExtraTerrestre::resetNombreExtraTerrestre();
		system("cls");
	} while (rejouer);

	return 0;
}


