#pragma once

class Saisie {
private:
	// Les attributs
	int touche;
public:
	// Les méthodes

	static char recupererTouche();
	static int validerNumerique();
	static int validerPlage(int borneMin, int borneMax);
	static char oui_non();



};