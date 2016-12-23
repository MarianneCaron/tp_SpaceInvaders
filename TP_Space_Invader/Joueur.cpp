#include "Joueur.h"

Joueur::Joueur() {

}

VaisseauDefender  &Joueur::getVaisseau() {
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
	if ((touche == 'k' && vaisseau.coord.getPositionX()>1)||( touche == 'l' && vaisseau.coord.getPositionX()<103) ){
		// Faire bouger le vaisseau
		vaisseau.modifierPositionDefender(touche);
	}
	return lancerLaser;
}