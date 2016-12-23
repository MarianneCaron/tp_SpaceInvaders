#include "Affichage.h"
#include "Saisie.h"
#include "ExtraTerrestre.h"
#include "UIKit.h"
#include <iostream>
using namespace std;

int niveau;
bool partieTermine;
bool rejouer;

void Affichage::init() {
	UIKit::setDimensionFenetre(0, 0, 180, 50);
}

int Affichage::menu() {

	// Affichage du menu
	UIKit::color( FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
	UIKit::gotoXY(0, 10);
	cout << " 					            ******  ********     ***     ******  ********                          " << endl;
	cout << " 					           **    ** **     **   ** **   **    ** **                                " << endl;
	cout << " 					           **       **     **  **   **  **       **                                " << endl;
	cout << " 					            ******  ********  **     ** **       ******                            " << endl;
	cout << " 					                 ** **        ********* **       **                                " << endl;
	cout << " 					           **    ** **        **     ** **    ** **                                " << endl;
	cout << " 					            ******  **        **     **  ******  ********                          " << endl << endl << endl;
	cout << "				  **** **    ** **     **    ***    ********  ******** ********   ******     **** **** " << endl;
	cout << "				   **  ***   ** **     **   ** **   **     ** **       **     ** **    **     **   **  " << endl;
	cout << "				   **  ****  ** **     **  **   **  **     ** **       **     ** **           **   **  " << endl;
	cout << " 				   **  ** ** ** **     ** **     ** **     ** ******   ********   ******      **   **  " << endl;
	cout << " 				   **  **  ****  **   **  ********* **     ** **       **   **         **     **   **  " << endl;
	cout << " 				   **  **   ***   ** **   **     ** **     ** **       **    **  **    **     **   **  " << endl;
	cout << " 				  **** **    **    ***    **     ** ********  ******** **     **  ******     **** **** " << endl;

	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);


	UIKit::gotoXY(68, 29);
	cout << "NIVEAU" << endl;
	UIKit::gotoXY(65, 33);
	cout << "1-Debutant" << endl;
	UIKit::gotoXY(65, 35);
	cout << "2-Intermediaire" << endl;
	UIKit::gotoXY(65, 37);
	cout << "3-Avance" << endl;
	UIKit::gotoXY(55, 40);
	cout << "A quel Niveau voulez-vous commencer?";
	int niveau;
	niveau = Saisie::validerPlage(1, 3);
	system("cls");
	return niveau;
}

void Affichage::dessinerCadre() {
	UIKit::cadre(0, 0, 145, 45, FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
	UIKit::cadre(0, 0, 110, 45, FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
	UIKit::curseurVisible(false);
}


void Affichage::afficherScore(int niveau, int score, int nbVies) {
	
	
	
	UIKit::gotoXY(125, 6);
	cout << "NIVEAU " << niveau;
	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY );
	UIKit::gotoXY(120, 10);
	cout << "Nombre de Martiens: " << ExtraTerrestre::getNombreExtraTerrestre();
	UIKit::gotoXY(120, 12);
	cout << "Score: " << score << "          ";
	UIKit::gotoXY(120, 14);
	cout << "Nombre de vies: " << nbVies << "       ";
	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);

	UIKit::gotoXY(125, 20);
	cout << "CONTROLE ";
	UIKit::gotoXY(115, 24);
	cout << "Tirer: barre d'espacement ";
	UIKit::gotoXY(115, 26);
	cout << "Vers la gauche: k ";
	UIKit::gotoXY(115, 28);
	cout << "Vers la droite: l ";

	UIKit::color(FOREGROUND_INTENSITY + FOREGROUND_RED);
	UIKit::gotoXY(120, 34);
	cout << "\\¤/ = 100 pts ";
	UIKit::color(FOREGROUND_GREEN + FOREGROUND_INTENSITY);
	UIKit::gotoXY(120, 36);
	cout << "\\±/ = 200 pts ";
	UIKit::color(FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
}

bool Affichage::affichageFinPartie(bool gagne, int & niveau) {
	system("cls");
	UIKit::gotoXY(70, 25);
	if (!gagne) {
		cout << "GAME OVER!";
	}
	else {
		cout << "VOUS AVEZ GAGNE!";
	}
	UIKit::gotoXY(65, 27);
	cout << "Voulez-vous rejouer? (o/n)";
	bool rejouer = ((Saisie::oui_non() == 'O') ? true : false);

	if (gagne && rejouer && niveau <= 2) {
		UIKit::gotoXY(65, 29);
		cout << "Voulez-vous passer au prochain niveau? (o/n)";
		if (Saisie::oui_non() == 'O') {
			(niveau)++;
		}
	}
	return rejouer;
}
