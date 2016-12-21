
#include "Coord.h"
#include "ExtraTerrestre.h"
#include "Laser.h"
#include "Martien.h"
#include "UIKit.h"
#include "Vaisseau.h"
#include "Saisie.h"
#include "Affichage.h"
#include "Timer.h"
#include <conio.h>
#include <time.h>	// pour time(int)
#include <stdlib.h>	// pour srand(int) et rand()
#include <iostream>
using namespace std;

//Déclaration des constantes
#define MAX_LASERS 80
#define MAX_ET 80

int main()
{

	// Assignation d'un srand pour les valeurs aléatoires
	srand((unsigned int)time(NULL));

	// Détermination des dimensions de la fenêtre de la console
	UIKit::setDimensionFenetre(0, 0, 500, 780);

	// Affichage du menu
	UIKit::gotoXY(0, 10);
	cout << "	 					            ******  ********     ***     ******  ********                          " << endl;
	cout << "	 					           **    ** **     **   ** **   **    ** **                                " << endl;
	cout << "	 					           **       **     **  **   **  **       **                                " << endl;
	cout << "	 					            ******  ********  **     ** **       ******                            " << endl;
	cout << "	 					                 ** **        ********* **       **                                " << endl;
	cout << "	 					           **    ** **        **     ** **    ** **                                " << endl;
	cout << "	 					            ******  **        **     **  ******  ********                          " << endl << endl << endl;
	cout << " 					  **** **    ** **     **    ***    ********  ******** ********   ******     **** **** " << endl;
	cout << " 					   **  ***   ** **     **   ** **   **     ** **       **     ** **    **     **   **  " << endl;
	cout << " 					   **  ****  ** **     **  **   **  **     ** **       **     ** **           **   **  " << endl;
	cout << " 					   **  ** ** ** **     ** **     ** **     ** ******   ********   ******      **   **  " << endl;
	cout << " 					   **  **  ****  **   **  ********* **     ** **       **   **         **     **   **  " << endl;
	cout << " 					   **  **   ***   ** **   **     ** **     ** **       **    **  **    **     **   **  " << endl;
	cout << " 					  **** **    **    ***    **     ** ********  ******** **     **  ******     **** **** " << endl;




	UIKit::gotoXY(70, 27);
	cout << "Niveau" << endl;
	UIKit::gotoXY(70, 31);
	cout << "1-Debutant" << endl;
	UIKit::gotoXY(70, 33);
	cout << "2-Intermediaire" << endl;
	UIKit::gotoXY(70, 35);
	cout << "3-Avance" << endl;
	UIKit::gotoXY(65, 40);
	cout << "A quel Niveau voulez-vous commencer?";
	int niveau;
	niveau= Saisie::validerPlage(1,3);
	system("cls");

	bool rejouer;
	// *************************************************Le jeu**************************************** //
	do {
		// Variable nécessaire à la boucle du jeu
		bool partieTermine = false;
		char touche;
		int tour = 0;
		int score = 0;
		

		// Affichage du cadre de jeu
		UIKit::cadre(0, 0, 40, 45, FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
		UIKit::curseurVisible(false);

		// Apparition du vaisseau
		Vaisseau leVaisseau;

		// Tableau de laser
		Laser lesLasers[MAX_LASERS];
		int nbLasers = 0;
		Timer lasersTimer[MAX_LASERS];

		// Tableau de Martien
		Martien * lesET[MAX_ET];
		Timer ETTimer[MAX_ET];

		//Timer pour l'apparition des ET
		Timer nouveauET(1000);

		// Tableau de collision
		char tabChar[2] = { 1, 2 };
		int nbChar = 2;

		// **********************************************Boucle de la partie*************************************************** //
		while (!partieTermine) {
			// Affichage des scores
			UIKit::gotoXY(100, 20);
			cout << "Nombre de ET: " << ExtraTerrestre::getNombreExtraTerrestre();
			UIKit::gotoXY(100, 22);
			cout << "Score: " << score;

			// Test de collision
			for (int i = 0; i < nbLasers; i++) {  // lit des lasers pas encore initialisé
				if ((lesLasers[i].coord.getPositionY()) - 1 == 1) {
					lesLasers[i].killLaser();
				}
				for (int j = 0; j < nbChar; i++) {
					if (UIKit::getCharXY(lesLasers[i].coord.getPositionX(), lesLasers[i].coord.getPositionY() - 1) == tabChar[j]) {
						lesLasers[i].killLaser();
						ExtraTerrestre::reduireNombreExtraTerrestre();
						score += lesET[i]->ajouterPoints();
					}
				}
			}

			// Faire bouger les lasers
			for (int i = 0; i < MAX_LASERS; i++)
				if (lesLasers[i].isAlive && lasersTimer[i].estPret()) {
					lesLasers[i].moveLaser();
				}

			// Action du joueur
			// Récupération de la touche
			touche = Saisie::recupererTouche();

			// Lancer un laser
			if (touche == ' ') {
				int i = 0;
				// chercher la premiere case avec un laser "dead"
				while (i < MAX_LASERS && lesLasers[i].isAlive) {
					i++;
				}
				// On y insère le nouveau laser
				if (i < MAX_LASERS) {
					lesLasers[i].startLaser(leVaisseau.coord.getPositionX());
					lasersTimer[i].setDelai(50);
				}
			}
			else if (touche == 'l' || touche == 'k') {
				// Faire bouger le vaisseau
				leVaisseau.modifierPosition(touche);
			}

			//Faire bouger les ET
			for (int i = 0; i < MAX_ET; i++) {
				if (i < ExtraTerrestre::getNombreExtraTerrestre() && ETTimer[i].estPret()) {
					lesET[i]->jiggleMartien();
				}
			}

			//Faire apparaitre les ET
			if (nouveauET.estPret() || tour == 0) {

				switch (rand() % 3) {
				case 0:
					lesET[Martien::getNombreExtraTerrestre()] = new Martien(1, 10);
					ETTimer[Martien::getNombreExtraTerrestre()].setDelai(1000);
					break;
				case 1:
					lesET[Martien::getNombreExtraTerrestre()] = new Martien(2, 20);
					ETTimer[Martien::getNombreExtraTerrestre()].setDelai(500);
					break;
				case 2:
					lesET[Martien::getNombreExtraTerrestre()] = new Martien(1, 10);
					ETTimer[Martien::getNombreExtraTerrestre()].setDelai(1000);
					break;
				}
				lesET[Martien::getNombreExtraTerrestre()]->resetExtraTerrestre();
				lesET[Martien::getNombreExtraTerrestre() - 1]->putExtraTerrestre();
				
			}


			// ****** Condition de fin de partie ************ //
			if (ExtraTerrestre::getNombreExtraTerrestre() == 15) {
				partieTermine = true;
				system("cls");
				UIKit::gotoXY(70, 25);
				cout << "GAME OVER!";
				UIKit::gotoXY(70, 27);
				cout << "Voulez-vous rejouer? (o/n)";
				rejouer = ((Saisie::oui_non() == 'O') ? true : false);

			}
			if (ExtraTerrestre::getNombreExtraTerrestre() == 0) {
				partieTermine = true;
				system("cls");
				UIKit::gotoXY(70, 25);
				cout << "VOUS AVEZ GAGNE!";
				UIKit::gotoXY(70, 27);
				cout << "Voulez-vous rejouer? (o/n)";
				rejouer = ((Saisie::oui_non() == 'O') ? true : false);
				if (niveau <= 2) {
					UIKit::gotoXY(70, 29);
					cout << "Voulez-vous passer au prochain niveau? (o/n)";
					if (Saisie::oui_non() == 'O') {
						(niveau)++;
					}
				}
			}
			
			tour++;
		}	//************************** Fin de la boucle de la partie ********************************************//
		nbLasers = 0;
		ExtraTerrestre::resetNombreExtraTerrestre();
		system("cls");
	}while (rejouer);
	UIKit::gotoXY(0, 50);
	return 0;
}


