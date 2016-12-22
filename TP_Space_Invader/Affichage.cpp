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
	UIKit::setDimensionFenetre(0, 0, 150, 50);
}

int Affichage::menu() {

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
	niveau = Saisie::validerPlage(1, 3);
	system("cls");
	return niveau;
}

void Affichage::dessinerCadre() {
	UIKit::cadre(0, 0, 145, 45, FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
	UIKit::cadre(0, 0, 110, 45, FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY + FOREGROUND_RED);
	UIKit::curseurVisible(false);
}


void Affichage::afficherScore(int score) {
	UIKit::gotoXY(120, 20);
	cout << "Nombre de ET: " << ExtraTerrestre::getNombreExtraTerrestre();
	UIKit::gotoXY(120, 22);
	cout << "Score: " << score << "   ";
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
	UIKit::gotoXY(70, 27);
	cout << "Voulez-vous rejouer? (o/n)";
	bool rejouer = ((Saisie::oui_non() == 'O') ? true : false);

	if (gagne && rejouer && niveau <= 2) {
		UIKit::gotoXY(70, 29);
		cout << "Voulez-vous passer au prochain niveau? (o/n)";
		if (Saisie::oui_non() == 'O') {
			(niveau)++;
		}
	}
	return rejouer;
}
