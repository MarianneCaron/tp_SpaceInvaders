#include "Joueur.h"




Joueur::Joueur() {

}

Vaisseau &Joueur::getVaisseau() {
	return vaisseau;
}

bool Joueur::operationVaisseau() {
	bool lancerLaser = false;

	// Récupération de la touche
	char touche = Saisie::recupererTouche();

	// Lancer un laser
	if (touche == ' ') {
		lancerLaser = true;
	}
	if (touche == 'l' || touche == 'k') {
		// Faire bouger le vaisseau
		vaisseau.modifierPosition(touche);
	}
	return lancerLaser;
}