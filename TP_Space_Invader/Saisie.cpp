#include "Saisie.h"

#include <conio.h>
#include <iostream>
using namespace std;

char Saisie::recupererTouche() {
	// 	utiliser la fonction _kbhit() de conio.h qui retourne une valeur non
	//	nulle si une touche a été pressée

	char touche;
	if (_kbhit() != 0)
		touche = _getch(); // Pour aller chercher la touche sur laquelle le joeur a appuyé
	else
		touche = 0;
	return touche;
}

// Fonction pour la validation numérique des saisies
int Saisie::validerNumerique() {
	int n;
	bool estValide = false;

	do
	{
		cin >> n;

		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(512, '\n');
			cout << "Ceci n'est pas un nombre valide" << endl;
		}
		else {
			estValide = true;
		}
	} while (estValide == false);

	return n;
}

// Fonction pour la validation des plages de la saisie
int Saisie::validerPlage(int borneMin, int borneMax) {
	int nombreSaisi;
	bool estValide;

	do
	{
		nombreSaisi = Saisie::validerNumerique();
		if (nombreSaisi<borneMin || nombreSaisi>borneMax) {
			cout << "Ce nombre n'est pas entre " << borneMin << " et " << borneMax << "." << endl;
			estValide = false;
		}
		else {
			estValide = true;
		}
	} while (estValide == false);

	return nombreSaisi;
}

// Fonction pour valider et uniformiser les réponses en oui/non

char Saisie::oui_non() {
	char caractere;
	do
	{
		caractere = toupper(_getche());
		if ((caractere != 'O') && (caractere != 'N')) { //Faire afficher un message d'erreur 
			cout << endl << "Valeur invalide! - Veuillez entrer 'o' ou 'n': ";
		}
	} while ((caractere != 'O') && (caractere != 'N'));
	return caractere;
}
